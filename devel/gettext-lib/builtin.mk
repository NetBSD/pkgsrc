# $NetBSD: builtin.mk,v 1.16 2004/11/28 19:19:52 jlam Exp $

.for _lib_ in intl
.  if !defined(_BLNK_LIB_FOUND.${_lib_})
_BLNK_LIB_FOUND.${_lib_}!=	\
	if ${TEST} "`${ECHO} /usr/lib/lib${_lib_}.*`" != "/usr/lib/lib${_lib_}.*"; then \
		${ECHO} "yes";						\
	elif ${TEST} "`${ECHO} /lib/lib${_lib_}.*`" != "/lib/lib${_lib_}.*"; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
BUILDLINK_VARS+=	_BLNK_LIB_FOUND.${_lib_}
.  endif
.endfor
.undef _lib_

_LIBINTL_H=	/usr/include/libintl.h

.if !defined(IS_BUILTIN.gettext)
IS_BUILTIN.gettext=	no
.  if exists(${_LIBINTL_H}) && !empty(_BLNK_LIB_FOUND.intl:M[yY][eE][sS])
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

#.if defined(USE_BUILTIN.iconv) && !empty(USE_BUILTIN.iconv:M[nN][oO])
#USE_BUILTIN.gettext=	no
#.endif

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
.    if (${OPSYS} == "Linux") && exists(${_LIBICONV_H})
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
.  if ${_BLNK_LIB_FOUND.intl} == "yes"
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
#
# Determine if we need to include the libiconv buildlink3.mk file.
# We need to if we're using the pkgsrc gettext, and the version is
# at least gettext>=0.11.5nb1.
#
_GETTEXT_ICONV_DEPENDS=	gettext-lib>=0.11.5nb1
.  if !defined(_GETTEXT_NEEDS_ICONV)
_GETTEXT_NEEDS_ICONV?=	no
.    for _depend_ in ${BUILDLINK_DEPENDS.gettext}
.      if !empty(_GETTEXT_NEEDS_ICONV:M[nN][oO])
_GETTEXT_NEEDS_ICONV!=	\
	if ${PKG_INFO} -qe '${_depend_}'; then				\
		pkg=`${PKG_BEST_EXISTS} '${_depend_}'`;			\
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
.  if !empty(_GETTEXT_NEEDS_ICONV:M[yY][eE][sS])
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

BUILDLINK_LDADD.gettext?=	${_BLNK_LIBINTL}

# Some GNU configure scripts generated with an older and broken gettext.m4
# fail to detect if gettext is present or not because it fails to add
# "-lintl" to the linker command line.
#
# If BROKEN_GETTEXT_DETECTION is "yes", then automatically add "-lintl"
# (and "-liconv" if necessary) to LIBS to workaround this brokenness.
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
.  if !empty(_BLNK_LIB_FOUND.intl:M[yY][eE][sS])
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

SUBST_CLASSES+=			fix-msgfmt
SUBST_STAGE.fix-msgfmt=		post-wrapper
SUBST_MESSAGE.fix-msgfmt=	"Fixing paths in msgfmt wrapper."
SUBST_FILES.fix-msgfmt=		${BUILDLINK_DIR}/bin/msgfmt
SUBST_SED.fix-msgfmt=		-e 's|@PERL@|${PERL5}|g'
SUBST_SED.fix-msgfmt+=		-e 's|@MSGFMT@|${BUILDLINK_PREFIX.gettext}/bin/msgfmt|g'

BUILDLINK_TARGETS+=	buildlink-msgfmt

buildlink-msgfmt:
	@${CP} ../../devel/gettext/files/msgfmt.pl ${BUILDLINK_DIR}/bin/msgfmt
	@${CHMOD} +x ${BUILDLINK_DIR}/bin/msgfmt
.endif

.endif	# CHECK_BUILTIN.gettext
