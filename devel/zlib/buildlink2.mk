# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/06/21 23:00:29 jlam Exp $

.if !defined(ZLIB_BUILDLINK2_MK)
ZLIB_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.zlib?=	zlib>=1.1.3
BUILDLINK_PKGSRCDIR.zlib?=	../../devel/zlib

.if exists(/usr/include/zlib.h)
_NEED_ZLIB=		NO
.else
_NEED_ZLIB=		YES
.endif

.if ${_NEED_ZLIB} == "YES"
BUILDLINK_PACKAGES+=		zlib
EVAL_PREFIX+=	BUILDLINK_PREFIX.zlib=zlib
BUILDLINK_PREFIX.zlib_DEFAULT=	${LOCALBASE}
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
