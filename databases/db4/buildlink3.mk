# $NetBSD: buildlink3.mk,v 1.11 2004/03/18 09:12:09 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
DB4_BUILDLINK3_MK:=	${DB4_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	db4
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndb4}
BUILDLINK_PACKAGES+=	db4

.if !empty(DB4_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.db4+=		db4>=4.2.52
BUILDLINK_PKGSRCDIR.db4?=	../../databases/db4
.  if defined(USE_DB185)
BUILDLINK_DEPENDS.db4+=		db4>=4.2.52nb1	# older ones didn't enable
						# db-1.85 compat
BUILDLINK_INCDIRS.db4?=		include/db4
BUILDLINK_TRANSFORM+=		l:db:db4
.  endif
.endif	# DB4_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
