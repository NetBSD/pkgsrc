# $NetBSD: buildlink2.mk,v 1.3 2004/04/08 17:30:52 drochner Exp $
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

BUILDLINK_TARGETS+=	libcddb-buildlink

libcddb-buildlink: _BUILDLINK_USE

.endif	# LIBCDDB_BUILDLINK2_MK
