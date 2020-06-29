# $NetBSD: buildlink3.mk,v 1.1 2020/06/29 13:30:35 ryoon Exp $

BUILDLINK_TREE+=	db18

.if !defined(DB18_BUILDLINK3_MK)
DB18_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.db18+=	db18>=18.1.40
BUILDLINK_PKGSRCDIR.db18?=	../../databases/db18
BUILDLINK_INCDIRS.db18?=	include/db18
BUILDLINK_LDADD.db18=		-ldb18
BUILDLINK_TRANSFORM+=		l:db-18:db6

.if defined(USE_DB185) && !empty(USE_DB185:M[yY][eE][sS])
BUILDLINK_TRANSFORM+=		l:db:db18
.endif

PTHREAD_OPTS+=	native
.include "../../mk/pthread.buildlink3.mk"
.endif	# DB18_BUILDLINK3_MK

BUILDLINK_TREE+=	-db18
