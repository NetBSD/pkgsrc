# $NetBSD: builtin.mk,v 1.4 2004/03/29 05:43:30 jlam Exp $

.if !defined(_BLNK_LIBINTL_FOUND)
_BLNK_LIBINTL_FOUND!=	\
	if [ "`${ECHO} /usr/lib/libintl.*`" = "/usr/lib/libintl.*" ]; then \
		${ECHO} "no";						\
	else								\
		${ECHO} "yes";						\
	fi
BUILDLINK_VARS+=	_BLNK_LIBINTL_FOUND
.endif

_LIBINTL_H=	/usr/include/libintl.h

.if !defined(IS_BUILTIN.gettext)
IS_BUILTIN.gettext=	no
.  if !empty(_BLNK_LIBINTL_FOUND:M[yY][eE][sS]) && exists(${_LIBINTL_H})
IS_BUILTIN.gettext!=	\
	if ${GREP} -q "\#define[ 	]*__USE_GNU_GETTEXT" ${_LIBINTL_H}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    if !empty(IS_BUILTIN.gettext:M[yY][eE][sS])
# XXX
# XXX Consider the native libintl to be gettext-lib-0.10.35nb1.
# XXX
BUILTIN_PKG.gettext=	gettext-lib-0.10.35nb1
BUILDLINK_VARS+=	BUILTIN_PKG.gettext
.    endif
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.gettext
.endif	# IS_BUILTIN.gettext

#.if defined(USE_BUILTIN.iconv) && !empty(USE_BUILTIN.iconv:M[nN][oO])
#USE_BUILTIN.gettext=	no
#.endif

.if !defined(USE_BUILTIN.gettext)
USE_BUILTIN.gettext?=	${IS_BUILTIN.gettext}
PREFER.getext?=		pkgsrc

.  if defined(BUILTIN_PKG.gettext)
USE_BUILTIN.gettext=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.gettext}
.      if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
USE_BUILTIN.gettext!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.gettext}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif

.  if ${PREFER.gettext} == "native"
# XXX
# XXX By default, assume that the native gettext implementation is good
# XXX enough.
# XXX
.    if exists(${_LIBINTL_H})
USE_BUILTIN.gettext=	yes
#
# The listed platforms have an implementation of gettext that isn't
# GNUish enough.
#
_INCOMPAT_GETTEXT=	SunOS-*-*
.      for _pattern_ in ${_INCOMPAT_GETTEXT} ${INCOMPAT_GETTEXT}
.        if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.gettext=   no
.        endif
.      endfor
.    endif
.  endif

.  if defined(USE_GNU_GETTEXT)
.    if !empty(IS_BUILTIN.gettext:M[nN][oO]) || \
        (${PREFER.gettext} == "pkgsrc")
USE_BUILTIN.gettext=	no
.    endif
.  endif
.endif	# USE_BUILTIN.gettext

CHECK_BUILTIN.gettext?=	no
.if !empty(CHECK_BUILTIN.gettext:M[nN][oO])

.if !empty(USE_BUILTIN.gettext:M[nN][oO])
_BLNK_LIBINTL=		-lintl
_GETTEXT_ICONV_DEPENDS=	gettext-lib>=0.11.5nb1
.  if !defined(_GETTEXT_NEEDS_ICONV)
_GETTEXT_NEEDS_ICONV?=	no
.    for _depend_ in ${BUILDLINK_DEPENDS.gettext}
.      if !empty(_GETTEXT_NEEDS_ICONV:M[nN][oO])
_GETTEXT_NEEDS_ICONV!=	\
	if ${PKG_INFO} -qe '${_depend_}'; then				\
		pkg=`cd ${_PKG_DBDIR}; ${PKG_ADMIN} -S lsbest '${_depend_}'`; \
		if ${PKG_INFO} -qN "$$pkg" | ${GREP} -q "libiconv-[0-9]"; then \
			${ECHO} "yes";					\
		else							\
			${ECHO} "no";					\
		fi;							\
	else								\
		${ECHO} "yes";						\
	fi
.      endif
.    endfor
.  endif
.  if ${_GETTEXT_NEEDS_ICONV} == "yes"
.    for _mkfile_ in buildlink3.mk builtin.mk
.      if exists(../../converters/libiconv/${_mkfile_})
BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
.        include "../../converters/libiconv/${_mkfile_}"
BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
.      endif
.    endfor
BUILDLINK_DEPENDS.gettext+=	${_GETTEXT_ICONV_DEPENDS}
_BLNK_LIBINTL+=			${BUILDLINK_LDADD.iconv}
.  endif
.endif

.if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
.  if ${_BLNK_LIBINTL_FOUND} == "yes"
_BLNK_LIBINTL=		-lintl
.  else
_BLNK_LIBINTL=		# empty
BUILDLINK_TRANSFORM+=	l:intl:
.  endif
.endif

BUILDLINK_LDADD.gettext?=	${_BLNK_LIBINTL}

# Add -lintl to LIBS in CONFIGURE_ENV to work around broken gettext.m4:
# older gettext.m4 does not add -lintl where it should, and the resulting
# configure script fails to detect if libintl.a is the genuine GNU gettext
# or not.
#
.if defined(GNU_CONFIGURE)
LIBS+=			${BUILDLINK_LDADD.gettext}
CONFIGURE_ENV+=		INTLLIBS="${BUILDLINK_LDADD.gettext}"
.  if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
.    if ${_BLNK_LIBINTL_FOUND} == "yes"
CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl="yes"
.    endif
.  endif
.  if !empty(USE_BUILTIN.gettext:M[nN][oO])
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext}
.  else
CONFIGURE_ARGS+=	--without-libintl-prefix
.  endif
.endif

.endif	# CHECK_BUILTIN.gettext
