# $NetBSD: buildlink3.mk,v 1.1 2004/03/06 22:37:40 snj Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.3.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.

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
