# $NetBSD: buildlink3.mk,v 1.27 2012/02/05 12:16:56 obache Exp $

BUILDLINK_TREE+=	db2

.if !defined(DB_BUILDLINK3_MK)
DB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.db2+=		db>=2.7.3
BUILDLINK_ABI_DEPENDS.db2+=	db>=2.7.7nb2
BUILDLINK_PKGSRCDIR.db2?=	../../databases/db
BUILDLINK_INCDIRS.db2?=		include/db2
BUILDLINK_LDADD.db2=		-ldb2

.  include "../../mk/bsd.fast.prefs.mk"
.  if defined(USE_DB185) && !empty(USE_DB185:M[yY][eE][sS])
#BUILDLINK_LIBS.db2=		${BUILDLINK_LDADD.db2}
BUILDLINK_TRANSFORM+=		l:db:db2
.  endif
.endif # DB_BUILDLINK3_MK

BUILDLINK_TREE+=	-db2
