# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:07 jlam Exp $
#
# This Makefile fragment is included by packages that use zlib. 
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.zlib to the dependency pattern
#     for the version of zlib desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(ZLIB_BUILDLINK2_MK)
ZLIB_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.zlib?=	zlib>=1.1.3

.if exists(/usr/include/zlib.h)
_NEED_ZLIB=		NO
.else
_NEED_ZLIB=		YES
.endif

.if ${_NEED_ZLIB} == "YES"
DEPENDS+=		${BUILDLINK_DEPENDS.zlib}:../../devel/zlib
BUILDLINK_PREFIX.zlib=	${LOCALBASE}
.else
BUILDLINK_PREFIX.zlib=	/usr
.endif

BUILDLINK_FILES.zlib=	include/zconf.h
BUILDLINK_FILES.zlib+=	include/zlib.h
BUILDLINK_FILES.zlib+=	lib/libz.*

BUILDLINK_TARGETS+=	zlib-buildlink

.if ${_NEED_ZLIB} == "NO"
LIBTOOL_ARCHIVE_UNTRANSFORM_SED+= \
	-e "s|${LOCALBASE}/lib/libz.la|-L${BUILDLINK_PREFIX.zlib}/lib -lz|g"
.endif

zlib-buildlink: _BUILDLINK_USE

.endif	# ZLIB_BUILDLINK2_MK
