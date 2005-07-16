# $NetBSD: builtin.mk,v 1.26 2005/07/16 01:19:08 jlam Exp $

BUILTIN_PKG:=	gettext

BUILTIN_FIND_LIBS:=		intl
BUILTIN_FIND_FILES_VAR:=	H_GETTEXT
BUILTIN_FIND_FILES.H_GETTEXT=	/usr/include/libintl.h
BUILTIN_FIND_GREP.H_GETTEXT=	\#define[ 	]*__USE_GNU_GETTEXT

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.gettext)
IS_BUILTIN.gettext=	no
.  if empty(H_GETTEXT:M${LOCALBASE}/*) && exists(${H_GETTEXT}) && \
      !empty(BUILTIN_LIB_FOUND.intl:M[yY][eE][sS])
IS_BUILTIN.gettext=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.gettext

_BLTN_H_GETTEXT=	/usr/include/libintl.h
.if !defined(BUILTIN_GETTEXT_NGETTEXT)
BUILTIN_GETTEXT_NGETTEXT=	no
.  if exists(${_BLTN_H_GETTEXT})
BUILTIN_GETTEXT_NGETTEXT!=						\
	if ${GREP} -q "char.*ngettext" ${_BLTN_H_GETTEXT:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.  endif
.endif
MAKEVARS+=	BUILTIN_GETTEXT_NGETTEXT

###
### Determine whether we should use the built-in implementation if it
### exists, and uset USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.gettext)
.  if ${PREFER.gettext} == "pkgsrc"
USE_BUILTIN.gettext=	no
.  else
USE_BUILTIN.gettext=	${IS_BUILTIN.gettext}
.    if defined(BUILTIN_PKG.gettext) && \
        !empty(IS_BUILTIN.gettext:M[yY][eE][sS])
USE_BUILTIN.gettext=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.gettext}
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
.    if !defined(_BLTN_REPLACE.gettext)
_BLTN_REPLACE.gettext=	no
# XXX
# XXX By default, assume that the native gettext implementation is good
# XXX enough to replace GNU gettext if it is part of glibc (the GNU C
# XXX Library).
# XXX
.      if exists(${_BLTN_H_GETTEXT})
_BLTN_REPLACE.gettext!=							\
	if ${GREP} -q "This file is part of the GNU C Library" ${_BLTN_H_GETTEXT:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.      endif
.    endif
MAKEVARS+=	_BLTN_REPLACE.gettext
.    if !empty(_BLTN_REPLACE.gettext:M[yY][eE][sS])
USE_BUILTIN.gettext=	yes
.    endif
# XXX
# XXX By default, assume that the native gettext implementation is good
# XXX enough to replace GNU gettext if it supplies ngettext().
# XXX
.    if !empty(BUILTIN_GETTEXT_NGETTEXT:M[yY][eE][sS])
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

# If USE_GNU_GETTEXT is defined, then force the use of a GNU gettext
# implementation.
#
.if defined(USE_GNU_GETTEXT)
.  if !empty(IS_BUILTIN.gettext:M[nN][oO])
USE_BUILTIN.gettext=	no
.  endif
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.gettext?=	no
.if !empty(CHECK_BUILTIN.gettext:M[nN][oO])

######################################################################
# If we are using the builtin gettext implementation...
######################################################################
.  if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
.    if ${BUILTIN_LIB_FOUND.intl} == "yes"
_BLTN_LIBINTL=		-lintl
.    else
_BLTN_LIBINTL=		# empty
BUILDLINK_TRANSFORM+=	rm:-lintl
.    endif
.  endif

######################################################################
# If we are using pkgsrc gettext implementation...
######################################################################
.  if !empty(USE_BUILTIN.gettext:M[nN][oO])
_BLTN_LIBINTL=		-lintl
#
# Determine if we need to include the libiconv buildlink3.mk file.
# Since we're using the pkgsrc gettext, the only time we don't need
# iconv is if an already-installed gettext-lib package satisfied all
# of the gettext dependencies but is <0.11.5nb1.
#
_BLTN_GETTEXT_ICONV_DEPENDS=	gettext-lib>=0.11.5nb1
.    if !defined(_BLTN_GETTEXT_NEEDS_ICONV)
_BLTN_GETTEXT_NEEDS_ICONV?=	no
.      for _dep_ in ${BUILDLINK_DEPENDS.gettext}
.        if !empty(_BLTN_GETTEXT_NEEDS_ICONV:M[nN][oO])
_BLTN_GETTEXT_NEEDS_ICONV!=						\
	pkg=`${PKG_BEST_EXISTS} ${_dep_:Q}`;				\
	if ${TEST} -z "$$pkg"; then					\
		${ECHO} yes;						\
	elif ${PKG_ADMIN} pmatch ${_BLTN_GETTEXT_ICONV_DEPENDS:Q} "$$pkg"; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
MAKEVARS+=	_BLTN_GETTEXT_NEEDS_ICONV

.    if !empty(_BLTN_GETTEXT_NEEDS_ICONV:M[yY][eE][sS])
.      for _mkfile_ in buildlink3.mk builtin.mk
BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
.        sinclude "../../converters/libiconv/${_mkfile_}"
BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
.      endfor
BUILDLINK_DEPENDS.gettext+=	${_BLTN_GETTEXT_ICONV_DEPENDS}
_BLTN_LIBINTL+=			${BUILDLINK_LDADD.iconv}
.    endif
.  endif

BUILDLINK_LDADD.gettext?=	${_BLTN_LIBINTL}

# Some GNU configure scripts generated with an older and broken gettext.m4
# fail to detect if gettext is present or not because it fails to add
# "-lintl" to the linker command line.
#
# If BROKEN_GETTEXT_DETECTION is "yes", then automatically add "-lintl"
# to LIBS to workaround this brokenness.
#
# XXX Nowadays, most packages' GNU configure scripts correctly detect
# XXX -lintl, so this should really default to "no", but we'll leave it
# XXX as "yes" until we can do a full bulk build test.
#
BROKEN_GETTEXT_DETECTION?=	yes
.  if !empty(BROKEN_GETTEXT_DETECTION:M[yY][eE][sS])
BUILDLINK_LIBS.gettext+=	${BUILDLINK_LDADD.gettext}
CONFIGURE_ENV+=			INTLLIBS="${BUILDLINK_LDADD.gettext}"
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
.        if !empty(BUILTIN_GETTEXT_NGETTEXT:M[yY][eE][sS])
CONFIGURE_ENV+=		gt_cv_func_gnugettext2_libintl="yes"
.        endif
.      endif
.    endif
.    if !empty(USE_BUILTIN.gettext:M[nN][oO])
CONFIGURE_ARGS+=	--with-libintl-prefix="${BUILDLINK_PREFIX.gettext}"
.    else
CONFIGURE_ARGS+=	--without-libintl-prefix
.    endif
.  endif

.  if defined(USE_MSGFMT_PLURALS) && !empty(USE_MSGFMT_PLURALS:M[Yy][Ee][Ss])
USE_TOOLS+=		perl
CONFIGURE_ENV+=		MSGFMT=${BUILDLINK_DIR}/bin/msgfmt

# XXX _USE_NEW_TOOLS=yes should make "msgfmt" and "msgfmt-plural" into
# XXX tools that can be specified via USE_TOOLS.  They would replace
# XXX BUILD_USES_MSGFMT and USE_MSGFMT_PLURALS.
# XXX
BUILDLINK_TARGETS+=	buildlink-msgfmt

buildlink-msgfmt: ${BUILDLINK_DIR}/bin/msgfmt

${BUILDLINK_DIR}/bin/msgfmt: ${.CURDIR}/../../devel/gettext/files/msgfmt.pl
	@${MKDIR} ${.TARGET:H}
	@${CAT} ${.ALLSRC} |						\
	 ${SED} -e "s|@PERL@|"${PERL5:Q}"|g"				\
		-e "s|@MSGFMT@|"${BUILDLINK_PREFIX.gettext:Q}/bin/msgfmt"|g" \
		> ${.TARGET}
	@${CHMOD} +x ${.TARGET}
.  endif

.endif	# CHECK_BUILTIN.gettext
