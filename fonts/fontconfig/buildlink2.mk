# $NetBSD: buildlink2.mk,v 1.8 2004/02/16 22:47:23 jlam Exp $

.if !defined(FONTCONFIG_BUILDLINK2_MK)
FONTCONFIG_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.fontconfig?=		fontconfig>=2.1nb1
BUILDLINK_PKGSRCDIR.fontconfig?=	../../fonts/fontconfig

# Check if we got fontconfig distributed with XFree86 4.x or if we need to
# depend on the fontconfig package.
#
_REQUIRE_BUILTIN_FONTCONFIG?=	NO

_FONTCONFIG_FONTCONFIG_H=	${X11BASE}/include/fontconfig/fontconfig.h
_X11_TMPL=			${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(_BUILTIN_FONTCONFIG)
_BUILTIN_FONTCONFIG=	NO
.  if exists(${_FONTCONFIG_FONTCONFIG_H}) && exists(${_X11_TMPL})
_IS_BUILTIN.fontconfig!=						\
	if ${GREP} -q BuildFontconfigLibrary ${_X11_TMPL}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
_BUILTIN_FONTCONFIG= ${_IS_BUILTIN.fontconfig}
.    if !empty(_IS_BUILTIN.fontconfig:M[yY][eE][sS])
#
# Create an appropriate package name for the built-in fontconfig distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
_FONTCONFIG_MAJOR!=	\
	${AWK} '/\#define[ 	]*FC_MAJOR/ { print $$3 }'		\
		${_FONTCONFIG_FONTCONFIG_H}
_FONTCONFIG_MINOR!=	\
	${AWK} '/\#define[ 	]*FC_MINOR/ { print $$3 }'		\
		${_FONTCONFIG_FONTCONFIG_H}
_FONTCONFIG_REVISION!=	\
	${AWK} '/\#define[ 	]*FC_REVISION/ { print $$3 }'		\
		${_FONTCONFIG_FONTCONFIG_H}
_FONTCONFIG_VERSION=	\
	${_FONTCONFIG_MAJOR}.${_FONTCONFIG_MINOR}.${_FONTCONFIG_REVISION}
_FONTCONFIG_PKG=		fontconfig-${_FONTCONFIG_VERSION}

_BUILTIN_FONTCONFIG?=	YES
.      for _depend_ in ${BUILDLINK_DEPENDS.fontconfig}
.        if !empty(_BUILTIN_FONTCONFIG:M[yY][eE][sS])
_BUILTIN_FONTCONFIG!=							\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_FONTCONFIG_PKG}; then	\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.    endif
.  endif
MAKEFLAGS+=	_BUILTIN_FONTCONFIG=${_BUILTIN_FONTCONFIG}
.endif

.if !empty(_BUILTIN_FONTCONFIG:M[yY][eE][sS])
_NEED_FONTCONFIG=	NO
.else
_NEED_FONTCONFIG=	YES
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    ${_BUILTIN_FONTCONFIG} == "YES"
_NEED_FONTCONFIG=	NO
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
_NEED_FONTCONFIG=	YES
.endif
.if !empty(PREFER_NATIVE:Mfontconfig) && \
    ${_BUILTIN_FONTCONFIG} == "YES"
_NEED_FONTCONFIG=	NO
.endif
.if !empty(PREFER_PKGSRC:Mfontconfig)
_NEED_FONTCONFIG=	YES
.endif

.if !empty(_REQUIRE_BUILTIN_FONTCONFIG:M[yY][eE][sS])
_NEED_FONTCONFIG=	NO
.endif

.if ${_NEED_FONTCONFIG} == "YES"
BUILDLINK_PACKAGES+=			fontconfig
EVAL_PREFIX+=	BUILDLINK_PREFIX.fontconfig=fontconfig
BUILDLINK_PREFIX.fontconfig_DEFAULT=	${X11PREFIX}
#
# If we depend on the package, depend on the latest version
# with a library minor bump.
#
BUILDLINK_DEPENDS.fontconfig=	fontconfig>=2.1nb2
.else
BUILDLINK_PREFIX.fontconfig=	${X11BASE}
.endif

BUILDLINK_FILES.fontconfig+=    include/fontconfig/fcfreetype.h
BUILDLINK_FILES.fontconfig+=    include/fontconfig/fcprivate.h
BUILDLINK_FILES.fontconfig+=    include/fontconfig/fontconfig.h
BUILDLINK_FILES.fontconfig+=    lib/libfontconfig.*

USE_X11=	yes

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"

BUILDLINK_TARGETS+=		fontconfig-buildlink

fontconfig-buildlink: _BUILDLINK_USE

.endif	# FONTCONFIG_BUILDLINK2_MK
