# $NetBSD: buildlink2.mk,v 1.2 2004/01/17 15:32:33 recht Exp $
#

.if !defined(LIBCDDB_BUILDLINK2_MK)
LIBCDDB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libcddb
BUILDLINK_DEPENDS.libcddb?=		libcddb>=0.9.4
BUILDLINK_PKGSRCDIR.libcddb?=		../../audio/libcddb

EVAL_PREFIX+=	BUILDLINK_PREFIX.libcddb=libcddb
BUILDLINK_PREFIX.libcddb_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libcddb+=	include/cddb/*.h
BUILDLINK_FILES.libcddb+=	lib/libcddb.*

.include "../../misc/libcdio/buildlink2.mk"

BUILDLINK_TARGETS+=	libcddb-buildlink

libcddb-buildlink: _BUILDLINK_USE

.endif	# LIBCDDB_BUILDLINK2_MK
