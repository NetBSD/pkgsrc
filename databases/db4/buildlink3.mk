# $NetBSD: buildlink3.mk,v 1.14 2004/03/30 16:20:19 jlam Exp $

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
BUILDLINK_INCDIRS.db4?=		include/db4
BUILDLINK_TRANSFORM+=		l:db-4:db4
USE_DB185?=			yes
.  if !empty(USE_DB185:M[yY][eE][sS])
#
# Older db4 packages didn't enable the db-1.85 compatibility API.
#
BUILDLINK_DEPENDS.db4+=		db4>=4.2.52nb1
BUILDLINK_TRANSFORM+=		l:db:db4
.  endif
.endif	# DB4_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
