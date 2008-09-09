# $NetBSD: buildlink3.mk,v 1.1 2008/09/09 22:23:32 tron Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
DB46_BUILDLINK3_MK:=	${DB46_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	db46
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndb46}
BUILDLINK_PACKAGES+=	db46
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}db46

.if !empty(DB46_BUILDLINK3_MK:M+)
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
.endif	# DB46_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
