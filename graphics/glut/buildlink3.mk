# $NetBSD: buildlink3.mk,v 1.1 2004/01/03 23:06:44 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLUT_BUILDLINK3_MK:=	${GLUT_BUILDLINK3_MK}+

.if !empty(GLUT_BUILDLINK3_MK:M\+)
BUILDLINK_DEPENDS.glut?=	glut>=${MESA_VERSION}
BUILDLINK_PKGSRCDIR.glut?=	../../graphics/glut
.endif	# GLUT_BUILDLINK3_MK

.if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=	glut
.endif

.if !empty(GLUT_BUILDLINK3_MK:M\+)
BUILDLINK_PACKAGES+=	glut

.  include "../../graphics/MesaLib/buildlink3.mk"
.endif	# GLUT_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
