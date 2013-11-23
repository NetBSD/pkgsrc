# $NetBSD: builtin.mk,v 1.44 2013/11/23 11:29:35 obache Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILTIN_PKG:=	gettext

BUILTIN_FIND_LIBS:=			intl
BUILTIN_FIND_HEADERS_VAR:=		H_GETTEXT H_GENTOO_GETTEXT	\
					H_NGETTEXT_GETTEXT
BUILTIN_FIND_HEADERS.H_GETTEXT=		libintl.h
BUILTIN_FIND_GREP.H_GETTEXT=		\#define[ 	]*__USE_GNU_GETTEXT
BUILTIN_FIND_HEADERS.H_GENTOO_GETTEXT=	libintl.h
BUILTIN_FIND_GREP.H_GENTOO_GETTEXT=	gentoo-multilib/.*/libintl.h
BUILTIN_FIND_HEADERS.H_NGETTEXT_GETTEXT=libintl.h
BUILTIN_FIND_GREP.H_NGETTEXT_GETTEXT=	char.*ngettext

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
#
# Gentoo Linux has an unusual scheme where /usr/include/libintl.h
# pulls in gentoo-multilib/$ARCH/libintl.h, where the latter is the
# real libintl.h file.  We can safely assume that this is GNU gettext
# (in glibc).
#
.if !defined(IS_BUILTIN.gettext)
IS_BUILTIN.gettext=	no
.  if (empty(H_GETTEXT:M__nonexistent__) && \
       empty(H_GETTEXT:M${LOCALBASE}/*)) || \
      (empty(H_GENTOO_GETTEXT:M__nonexistent__) && \
       empty(H_GENTOO_GETTEXT:M${LOCALBASE}/*))
IS_BUILTIN.gettext=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.gettext

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.gettext)
.  if ${PREFER.gettext} == "pkgsrc"
USE_BUILTIN.gettext=	no
.  else
USE_BUILTIN.gettext=	${IS_BUILTIN.gettext}
.    if defined(BUILTIN_PKG.gettext) && \
	!empty(IS_BUILTIN.gettext:M[yY][eE][sS])
USE_BUILTIN.gettext=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.gettext}
.        if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
USE_BUILTIN.gettext!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.gettext:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
# XXX
# XXX By default, assume that the native gettext implementation is good
# XXX enough to replace GNU gettext if it supplies ngettext().
# XXX
.    if empty(H_NGETTEXT_GETTEXT:M__nonexistent__) && \
	empty(H_NGETTEXT_GETTEXT:M${LOCALBASE}/*)
USE_BUILTIN.gettext=	yes
.    endif
#
# Some platforms don't have a gettext implementation that can replace
# GNU gettext.
#
_INCOMPAT_GETTEXT?=	SunOS-*-*	# XXX move to mk/platforms/SunOS.mk
.    for _pattern_ in ${_INCOMPAT_GETTEXT} ${INCOMPAT_GETTEXT}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.gettext=	no
.      endif
.    endfor
.  endif  # PREFER.gettext
.endif
MAKEVARS+=	USE_BUILTIN.gettext

# Define BUILTIN_LIBNAME.gettext to be the base name of the built-in
# gettext library.
#
.if !empty(BUILTIN_LIB_FOUND.intl:M[yY][eE][sS])
BUILTIN_LIBNAME.gettext=	intl
.else
BUILTIN_LIBNAME.gettext=	# empty (part of the C library)
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.gettext?=	no
.if !empty(CHECK_BUILTIN.gettext:M[nN][oO])

.  if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
BUILDLINK_LIBNAME.gettext=	${BUILTIN_LIBNAME.gettext}
.    if empty(BUILTIN_LIBNAME.gettext)
BUILDLINK_TRANSFORM+=		rm:-lintl
.    endif
.  endif

# If using a built-in libintl that isn't from GNU gettext, then set up
# some GNU configure variables that are checked by modern gettext.m4
# so that it will detect "GNU gettext" in the existing libintl.
#
.  if defined(GNU_CONFIGURE)
.    if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
.      if !empty(BUILTIN_LIB_FOUND.intl:M[yY][eE][sS])
CONFIGURE_ENV+=		gt_cv_func_gnugettext_libintl="yes"
CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl="yes"
.	 if empty(H_NGETTEXT_GETTEXT:M__nonexistent__) && \
	    empty(H_NGETTEXT_GETTEXT:M${LOCALBASE}/*)
CONFIGURE_ENV+=		gt_cv_func_gnugettext2_libintl="yes"
.        endif
.      endif
.    endif
.    if !empty(USE_BUILTIN.gettext:M[nN][oO])
CONFIGURE_ARGS+=	--with-libintl-prefix="${BUILDLINK_PREFIX.gettext}"
.    endif
.  endif

.endif	# CHECK_BUILTIN.gettext
