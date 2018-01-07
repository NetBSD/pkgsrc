# $NetBSD: buildlink3.mk,v 1.24 2018/01/07 13:03:59 rillig Exp $

BUILDLINK_TREE+=	db3

.if !defined(DB3_BUILDLINK3_MK)
DB3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.db3+=	db3>=2.9.2
BUILDLINK_ABI_DEPENDS.db3+=	db3>=3.11.2nb3
BUILDLINK_PKGSRCDIR.db3?=	../../databases/db3
BUILDLINK_INCDIRS.db3?=		include/db3
BUILDLINK_LDADD.db3=		-ldb3
BUILDLINK_TRANSFORM+=		l:db-3:db3

.include "../../mk/bsd.fast.prefs.mk"
.if defined(USE_DB185) && !empty(USE_DB185:M[yY][eE][sS])
#BUILDLINK_LIBS.db3=		${BUILDLINK_LDADD.db3}
BUILDLINK_TRANSFORM+=		l:db:db3
.endif

.include "../../mk/pthread.buildlink3.mk"
.endif # DB3_BUILDLINK3_MK

BUILDLINK_TREE+=	-db3
