# $NetBSD: buildlink3.mk,v 1.2 2004/03/07 00:30:04 snj Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PHYSFS_BUILDLINK3_MK:=	${PHYSFS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	physfs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nphysfs}
BUILDLINK_PACKAGES+=	physfs

.if !empty(PHYSFS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.physfs+=	physfs>=0.1.8
BUILDLINK_PKGSRCDIR.physfs?=	../../devel/physfs

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif	# PHYSFS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
