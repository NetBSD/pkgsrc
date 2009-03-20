# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:05 joerg Exp $

BUILDLINK_TREE+=	db46

.if !defined(DB46_BUILDLINK3_MK)
DB46_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.db46+=	db46>=4.6.21
BUILDLINK_PKGSRCDIR.db46?=	../../databases/db46
BUILDLINK_INCDIRS.db46?=		include/db46
BUILDLINK_LDADD.db46=		-ldb46
BUILDLINK_TRANSFORM+=		l:db-4:db46 l:db46:db46

.  include "../../mk/bsd.fast.prefs.mk"
.  if defined(USE_DB185) && !empty(USE_DB185:M[yY][eE][sS])
BUILDLINK_LIBS.db46=		${BUILDLINK_LDADD.db46}
BUILDLINK_TRANSFORM+=		l:db:db46
.  endif

.  include "../../mk/compiler.mk"
.  if empty(PKGSRC_COMPILER:Mgcc)
PTHREAD_OPTS+=	native
.    include "../../mk/pthread.buildlink3.mk"
.  endif
.endif # DB46_BUILDLINK3_MK

BUILDLINK_TREE+=	-db46
