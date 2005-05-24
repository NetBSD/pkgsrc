# $NetBSD: builtin.mk,v 1.21 2005/05/24 05:41:32 jlam Exp $

BUILDLINK_FIND_LIBS:=	intl
.include "../../mk/buildlink3/find-libs.mk"

_LIBINTL_H=	/usr/include/libintl.h

.if !defined(IS_BUILTIN.gettext)
IS_BUILTIN.gettext=	no
.  if exists(${_LIBINTL_H}) && !empty(BUILDLINK_LIB_FOUND.intl:M[yY][eE][sS])
IS_BUILTIN.gettext!=	\
 	if ${GREP} -q "\#define[ 	]*__USE_GNU_GETTEXT" ${_LIBINTL_H}; then \
 		${ECHO} "yes";						\
 	else								\
 		${ECHO} "no";						\
 	fi
.  endif
.  if !empty(IS_BUILTIN.gettext:M[yY][eE][sS])
# XXX
# XXX Consider the native libintl to be gettext-lib-0.10.35nb1 until we
# XXX find a way to more accurately determine the version.
# XXX
BUILTIN_PKG.gettext=	gettext-lib-0.10.35nb1
BUILDLINK_VARS+=	BUILTIN_PKG.gettext
.  endif
.endif	# IS_BUILTIN.gettext

.if !defined(USE_BUILTIN.gettext)
USE_BUILTIN.gettext?=	${IS_BUILTIN.gettext}
PREFER.gettext?=		pkgsrc

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
# XXX enough if it has a prototype for ngettext().
# XXX
.    if !defined(_GETTEXT_NGETTEXT) && exists(${_LIBINTL_H})
_GETTEXT_NGETTEXT!=	\
	if ${GREP} -q "char.*ngettext" ${_LIBINTL_H}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
BUILDLINK_VARS+=	_GETTEXT_NGETTEXT
.      if !empty(_GETTEXT_NGETTEXT:M[yY][eE][sS])
USE_BUILTIN.gettext=	yes
.      else
USE_BUILTIN.gettext=	no
.      endif
.    endif
# XXX
# XXX By default, assume the native gettext on Linux systems using GLIBC
# XXX supports the GNU gettext API, and use it.
# XXX
.    if (${OPSYS} == "Linux")
USE_BUILTIN.gettext!=	\
	if ${GREP} -q "This file is part of the GNU C Library" ${_LIBINTL_H}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    endif
#
# The listed platforms have an implementation of gettext that isn't
# GNUish enough.
#
_INCOMPAT_GETTEXT=	SunOS-*-*
.    for _pattern_ in ${_INCOMPAT_GETTEXT} ${INCOMPAT_GETTEXT}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.gettext=   no
.      endif
.    endfor
.  endif # PREFER.gettext == "native"

.  if defined(USE_GNU_GETTEXT)
.    if !empty(IS_BUILTIN.gettext:M[nN][oO]) || \
        (${PREFER.gettext} == "pkgsrc")
USE_BUILTIN.gettext=	no
.    endif
.  endif
.endif	# USE_BUILTIN.gettext

CHECK_BUILTIN.gettext?=	no
.if !empty(CHECK_BUILTIN.gettext:M[nN][oO])

######################################################################
# If we are using the builtin gettext implementation...
######################################################################
.if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
.  if ${BUILDLINK_LIB_FOUND.intl} == "yes"
_BLNK_LIBINTL=		-lintl
.  else
_BLNK_LIBINTL=		# empty
BUILDLINK_TRANSFORM+=	rm:-lintl
.  endif
.endif

######################################################################
# If we are using pkgsrc gettext implementation...
######################################################################
.if !empty(USE_BUILTIN.gettext:M[nN][oO])
_BLNK_LIBINTL=		-lintl
.endif

BUILDLINK_LDADD.gettext?=	${_BLNK_LIBINTL}

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
.if !empty(BROKEN_GETTEXT_DETECTION:M[yY][eE][sS])
BUILDLINK_LIBS.gettext+=	${BUILDLINK_LDADD.gettext}
CONFIGURE_ENV+=			INTLLIBS="${BUILDLINK_LDADD.gettext}"
.endif	# BROKEN_GETTEXT_DETECTION

# If using a built-in libintl that isn't from GNU gettext, then set up
# some GNU configure variables that are checked by modern gettext.m4
# so that it will detect "GNU gettext" in the existing libintl.
#
.if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
.  if !empty(BUILDLINK_LIB_FOUND.intl:M[yY][eE][sS])
CONFIGURE_ENV+=		gt_cv_func_gnugettext_libintl="yes"
CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl="yes"
.    if defined(_GETTEXT_NGETTEXT) && !empty(_GETTEXT_NGETTEXT:M[yY][eE][sS])
CONFIGURE_ENV+=		gt_cv_func_gnugettext2_libintl="yes"
.    endif
.  endif
.endif

.if defined(GNU_CONFIGURE)
.  if !empty(USE_BUILTIN.gettext:M[nN][oO])
CONFIGURE_ARGS+=	--with-libintl-prefix="${BUILDLINK_PREFIX.gettext}"
.  else
CONFIGURE_ARGS+=	--without-libintl-prefix
.  endif
.endif

.if defined(USE_MSGFMT_PLURALS) && !empty(USE_MSGFMT_PLURALS:M[Yy][Ee][Ss])
USE_PERL5?=		build
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
.endif

.endif	# CHECK_BUILTIN.gettext
