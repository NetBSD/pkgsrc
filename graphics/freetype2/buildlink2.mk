# $NetBSD: buildlink2.mk,v 1.5 2002/10/08 09:32:33 jlam Exp $

.if !defined(FREETYPE2_BUILDLINK2_MK)
FREETYPE2_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.freetype2?=	freetype2>=2.0.1
BUILDLINK_PKGSRCDIR.freetype2?=	../../graphics/freetype2

# Check if we got FreeType2 distributed with XFree86 4.x or if we need to
# depend on the freetype2 package.
#
_REQUIRE_BUILTIN_FREETYPE2?=	NO

_FREETYPE_H=		${X11BASE}/include/freetype2/freetype/freetype.h
_X11_TMPL=		${X11BASE}/lib/X11/config/X11.tmpl
.if exists(${_FREETYPE_H}) && exists(${_X11_TMPL})
_IS_BUILTIN_FREETYPE2!= ${GREP} -c BuildFreetype2Library ${_X11_TMPL} || ${TRUE}
.else
_IS_BUILTIN_FREETYPE2=	0
.endif

.if !empty(_REQUIRE_BUILTIN_FREETYPE2:M[yY][eE][sS])
_NEED_FREETYPE2=	NO
.else
.  if ${_IS_BUILTIN_FREETYPE2} == "0"
_NEED_FREETYPE2=	YES
.  else
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
	${AWK} '/.*\#define.*FREETYPE_PATCH/ { print "."$$3 }' ${_FREETYPE_H}
_FREETYPE_VERSION=	${_FREETYPE_MAJOR}${_FREETYPE_MINOR}${_FREETYPE_PATCH}
_FREETYPE_PKG=		freetype2-${_FREETYPE_VERSION}
_FREETYPE_DEPENDS=	${BUILDLINK_DEPENDS.freetype2}
_NEED_FREETYPE2!= \
	if ${PKG_ADMIN} pmatch '${_FREETYPE_DEPENDS}' ${_FREETYPE_PKG}; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
.  endif
.endif

.if ${_NEED_FREETYPE2} == "YES"
BUILDLINK_PACKAGES+=			freetype2
EVAL_PREFIX+=	BUILDLINK_PREFIX.freetype2=freetype2
BUILDLINK_PREFIX.freetype2_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.freetype2=	${X11BASE}
.endif

BUILDLINK_FILES.freetype2=	include/ft2build.h
BUILDLINK_FILES.freetype2+=	include/freetype2/ft2build.h
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/*
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/cache/*
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/config/*
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/internal/*
BUILDLINK_FILES.freetype2+=	lib/libfreetype.*

BUILDLINK_TARGETS+=		freetype2-buildlink
BUILDLINK_TARGETS+=		freetype2-buildlink-config

_FREETYPE2_CONFIG= \
	${BUILDLINK_PREFIX.freetype2}/bin/freetype-config
_FREETYPE2_BUILDLINK_CONFIG= \
	${BUILDLINK_DIR}/bin/freetype-config

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

.endif	# FREETYPE2_BUILDLINK2_MK
