# $NetBSD: buildlink2.mk,v 1.1 2002/09/11 15:25:13 wiz Exp $
#

.if !defined(DB4_BUILDLINK2_MK)
DB4_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		db4
BUILDLINK_DEPENDS.db4?=		db4>=4.0.14
BUILDLINK_PKGSRCDIR.db4?=	../../databases/db4

EVAL_PREFIX+=	BUILDLINK_PREFIX.db4=db4
BUILDLINK_PREFIX.db4_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.db4+=	include/db4/cxx_common.h
BUILDLINK_FILES.db4+=	include/db4/cxx_except.h
BUILDLINK_FILES.db4+=	include/db4/db.h
BUILDLINK_FILES.db4+=	include/db4/db_cxx.h
BUILDLINK_FILES.db4+=	lib/libdb4.*
BUILDLINK_FILES.db4+=	lib/libdb4_cxx.*

BUILDLINK_TARGETS+=	db4-buildlink

db4-buildlink: _BUILDLINK_USE

.endif	# DB4_BUILDLINK2_MK
