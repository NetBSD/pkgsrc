# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/14 13:53:56 jdolecek Exp $

.if !defined(ZZIPLIB_BUILDLINK2_MK)
ZZIPLIB_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.zziplib?=	zziplib>=0.10.82
BUILDLINK_PKGSRCDIR.zziplib?=	../../archivers/zziplib

BUILDLINK_PACKAGES+=		zziplib
EVAL_PREFIX+=			BUILDLINK_PREFIX.zziplib=zziplib
BUILDLINK_PREFIX.zziplib_DEFAULT=	${LOCALBASE}
_BLNK_ZZIPLIB_LDFLAGS=		-L${BUILDLINK_PREFIX.zziplib}/lib -lzzip

LIBTOOL_ARCHIVE_UNTRANSFORM_SED+= \
	-e "s|${BUILDLINK_PREFIX.zziplib}/lib/libzzip.la|${_BLNK_ZZIPLIB_LDFLAGS}|g" \
	-e "s|${LOCALBASE}/lib/libzzip.la|${_BLNK_ZZIPLIB_LDFLAGS}|g"

BUILDLINK_FILES.zziplib=	include/zzip/* include/zzip*.h
BUILDLINK_FILES.zziplib+=	lib/libzzip.* lib/libzzip-0.*


BUILDLINK_TARGETS+=		zziplib-buildlink

zziplib-buildlink: _BUILDLINK_USE

.include "../../devel/zlib/buildlink2.mk"

.endif	# ZZIPLIB_BUILDLINK2_MK
