# $NetBSD: buildlink3.mk,v 1.2 2012/01/18 13:46:50 adam Exp $

BUILDLINK_TREE+=	db5

.if !defined(DB5_BUILDLINK3_MK)
DB5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.db5+=	db5>=5.0.21
BUILDLINK_ABI_DEPENDS.db5+=	db5>=5.3.15
BUILDLINK_PKGSRCDIR.db5?=	../../databases/db5
BUILDLINK_INCDIRS.db5?=		include/db5
BUILDLINK_LDADD.db5=		-ldb5
BUILDLINK_TRANSFORM+=		l:db-5:db5

.include "../../mk/bsd.fast.prefs.mk"
.if defined(USE_DB185) && !empty(USE_DB185:M[yY][eE][sS])
#BUILDLINK_LIBS.db5=		${BUILDLINK_LDADD.db5}
BUILDLINK_TRANSFORM+=		l:db:db5
.endif

PTHREAD_OPTS+=	native
.include "../../mk/pthread.buildlink3.mk"
.endif # DB5_BUILDLINK3_MK

BUILDLINK_TREE+=	-db5
