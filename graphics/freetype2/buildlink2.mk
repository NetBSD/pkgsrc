# $NetBSD: buildlink2.mk,v 1.18 2004/05/18 10:21:16 wiz Exp $

.if !defined(FREETYPE2_BUILDLINK2_MK)
FREETYPE2_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.freetype2?=	freetype2>=2.1.8
BUILDLINK_PKGSRCDIR.freetype2?=	../../graphics/freetype2

# Check if we got FreeType2 distributed with XFree86 4.x or if we need to
# depend on the freetype2 package.
#
_REQUIRE_BUILTIN_FREETYPE2?=	NO

_FREETYPE_H=		${X11BASE}/include/freetype2/freetype/freetype.h
_X11_TMPL=		${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(_BUILTIN_FREETYPE2)
_BUILTIN_FREETYPE2=	NO
.  if exists(${_FREETYPE_H}) && exists(${_X11_TMPL})
#
# Create an appropriate freetype2 package name for the built-in freetype2
# distributed with XFree86 4.x.  This package name can be used to check
# against BUILDLINK_DEPENDS.freetype2 to see if we need to install the
# pkgsrc freetype2 or if the built-in one is sufficient.
#
_FREETYPE_MAJOR!= \
	${AWK} '/.*\#define.*FREETYPE_MAJOR/ { print $$3 }' ${_FREETYPE_H}
_FREETYPE_MINOR!= \
	${AWK} '/.*\#define.*FREETYPE_MINOR/ { print "."$$3 }' ${_FREETYPE_H}
_FREETYPE_PATCH!= \
	${AWK} 'BEGIN { patch=0; } /.*\#define.*FREETYPE_PATCH/ { patch=$$3; } END { print "."patch; }' ${_FREETYPE_H}
_FREETYPE_VERSION=	${_FREETYPE_MAJOR}${_FREETYPE_MINOR}${_FREETYPE_PATCH}
_FREETYPE_PKG=		freetype2-${_FREETYPE_VERSION}
_FREETYPE_DEPENDS=	${BUILDLINK_DEPENDS.freetype2}
_BUILTIN_FREETYPE2!=	\
	if ${PKG_ADMIN} pmatch '${_FREETYPE_DEPENDS}' ${_FREETYPE_PKG}; then \
		if ${GREP} -q BuildFreetype2Library ${_X11_TMPL}; then	\
			${ECHO} "YES";					\
		else							\
			${ECHO} "NO";					\
		fi;							\
	else								\
		${ECHO} "NO";						\
	fi
.  endif
MAKEFLAGS+=	_BUILTIN_FREETYPE2=${_BUILTIN_FREETYPE2}
.endif

.if !empty(_BUILTIN_FREETYPE2:M[yY][eE][sS])
_NEED_FREETYPE2=	NO
.else
_NEED_FREETYPE2=	YES
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    ${_BUILTIN_FREETYPE2} == "YES"
_NEED_FREETYPE2=	NO
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
_NEED_FREETYPE2=	YES
.endif
.if !empty(PREFER_NATIVE:Mfreetype2) && \
    ${_BUILTIN_FREETYPE2} == "YES"
_NEED_FREETYPE2=	NO
.endif
.if !empty(PREFER_PKGSRC:Mfreetype2)
_NEED_FREETYPE2=	YES
.endif

.if !empty(_REQUIRE_BUILTIN_FREETYPE2:M[yY][eE][sS])
_NEED_FREETYPE2=	NO
.endif

.if ${_NEED_FREETYPE2} == "YES"
BUILDLINK_PACKAGES+=			freetype2
EVAL_PREFIX+=	BUILDLINK_PREFIX.freetype2=freetype2
BUILDLINK_PREFIX.freetype2_DEFAULT=	${LOCALBASE}
# If we depend on the package, depend on the latest version
# with a library major bump.
BUILDLINK_DEPENDS.freetype2=	freetype2>=2.1.3
.else
BUILDLINK_PREFIX.freetype2=	${X11BASE}
USE_X11=			# defined
.endif

BUILDLINK_FILES.freetype2=	bin/freetype-config
BUILDLINK_FILES.freetype2+=	include/ft2build.h
BUILDLINK_FILES.freetype2+=	include/freetype2/ft2build.h
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/*
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/cache/*
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/config/*
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/internal/*
BUILDLINK_FILES.freetype2+=	lib/libfreetype.*

BUILDLINK_TARGETS+=		freetype2-buildlink
BUILDLINK_TARGETS+=		freetype2-buildlink-config
BUILDLINK_TARGETS+=		freetype2-libfreetype-la

_FREETYPE2_CONFIG= \
	${BUILDLINK_PREFIX.freetype2}/bin/freetype-config
_FREETYPE2_BUILDLINK_CONFIG= \
	${BUILDLINK_DIR}/bin/freetype-config

.if ${_NEED_FREETYPE2} == "NO"
_BLNK_FREETYPE2_LDFLAGS=	-L${BUILDLINK_PREFIX.freetype2}/lib -lfreetype
LIBTOOL_ARCHIVE_UNTRANSFORM_SED+=	\
	-e "s|${BUILDLINK_PREFIX.freetype2}/lib/libfreetype.la|${_BLNK_FREETYPE2_LDFLAGS}|g" \
	-e "s|${LOCALBASE}/lib/libfreetype.la|${_BLNK_FREETYPE2_LDFLAGS}|g"
.endif

# packages expect to find the freetype headers in freetype/, so append
# the right path to CPPFLAGS.
CPPFLAGS+=		-I${BUILDLINK_PREFIX.freetype2}/include/freetype2

freetype2-buildlink: _BUILDLINK_USE

freetype2-buildlink-config:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${_FREETYPE2_CONFIG} ] &&				\
	   [ ! -f ${_FREETYPE2_BUILDLINK_CONFIG} ]; then		\
		${ECHO_BUILDLINK_MSG} "Creating config script ${_FREETYPE_BUILDLINK_CONFIG}."; \
		${MKDIR} ${_FREETYPE2_BUILDLINK_CONFIG:H};		\
		${SED}	-e "s|@AWK@|${AWK}|g"				\
			-e "s|@SED@|${SED}|g"				\
			-e "s|@X11BASE@|${X11BASE}|g"			\
			${.CURDIR}/../../graphics/freetype2/buildlink2-freetype-config.in \
			> ${_FREETYPE2_BUILDLINK_CONFIG};		\
		${CHMOD} +x ${_FREETYPE2_BUILDLINK_CONFIG};		\
	fi

freetype2-libfreetype-la:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	lafile="${BUILDLINK_DIR}/lib/libfreetype.la";			\
	libpattern="${BUILDLINK_PREFIX.freetype2}/lib/libfreetype.*";	\
	${BUILDLINK_FAKE_LA}

.endif	# FREETYPE2_BUILDLINK2_MK
