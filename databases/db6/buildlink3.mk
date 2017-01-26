# $NetBSD: buildlink3.mk,v 1.2 2017/01/26 11:03:17 adam Exp $

BUILDLINK_TREE+=	db6

.if !defined(DB6_BUILDLINK3_MK)
DB6_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.db6+=	db6>=6.2.23
BUILDLINK_ABI_DEPENDS.db6+=	db6>=6.2.23
BUILDLINK_PKGSRCDIR.db6?=	../../databases/db6
BUILDLINK_INCDIRS.db6?=		include/db6
BUILDLINK_LDADD.db6=		-ldb6
BUILDLINK_TRANSFORM+=		l:db-6:db6

.include "../../mk/bsd.fast.prefs.mk"
.if defined(USE_DB185) && !empty(USE_DB185:M[yY][eE][sS])
#BUILDLINK_LIBS.db6=		${BUILDLINK_LDADD.db6}
BUILDLINK_TRANSFORM+=		l:db:db6
.endif

PTHREAD_OPTS+=	native
.include "../../mk/pthread.buildlink3.mk"
.endif # DB6_BUILDLINK3_MK

BUILDLINK_TREE+=	-db6
