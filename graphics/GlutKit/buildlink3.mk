# $NetBSD: buildlink3.mk,v 1.1 2004/05/05 03:36:25 snj Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLUTKIT_BUILDLINK3_MK:=	${GLUTKIT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	GlutKit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NGlutKit}
BUILDLINK_PACKAGES+=	GlutKit

.if !empty(GLUTKIT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.GlutKit+=	GlutKit>=0.3.1r2nb4
BUILDLINK_RECOMMENDED.GlutKit?=	GlutKit>=0.3.1r2nb6
BUILDLINK_PKGSRCDIR.GlutKit?=	../../graphics/GlutKit
.endif	# GLUTKIT_BUILDLINK3_MK

.include "../../graphics/RenderKit/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
