# $NetBSD: buildlink3.mk,v 1.2 2016/03/05 11:27:49 jperkin Exp $
#

BUILDLINK_TREE+=	qore-glut-module

.if !defined(QORE_GLUT_MODULE_BUILDLINK3_MK)
QORE_GLUT_MODULE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore-glut-module+=	qore-glut-module>=0.0.3
BUILDLINK_ABI_DEPENDS.qore-glut-module?=	qore-glut-module>=0.0.3nb5
BUILDLINK_PKGSRCDIR.qore-glut-module?=	../../graphics/qore-glut-module

.include "../../graphics/qore-opengl-module/buildlink3.mk"
.endif	# QORE_GLUT_MODULE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore-glut-module
