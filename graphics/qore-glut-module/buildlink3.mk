# $NetBSD: buildlink3.mk,v 1.3 2016/07/22 13:16:39 nros Exp $
#

BUILDLINK_TREE+=	qore-glut-module

.if !defined(QORE_GLUT_MODULE_BUILDLINK3_MK)
QORE_GLUT_MODULE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore-glut-module+=	qore-glut-module>=0.0.3
BUILDLINK_ABI_DEPENDS.qore-glut-module?=	qore-glut-module>=0.0.3nb6
BUILDLINK_PKGSRCDIR.qore-glut-module?=	../../graphics/qore-glut-module

.include "../../graphics/qore-opengl-module/buildlink3.mk"
.endif	# QORE_GLUT_MODULE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore-glut-module
