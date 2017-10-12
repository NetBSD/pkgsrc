# $NetBSD: buildlink3.mk,v 1.4 2017/10/12 18:21:24 nros Exp $
#

BUILDLINK_TREE+=	qore-opengl-module

.if !defined(QORE_OPENGL_MODULE_BUILDLINK3_MK)
QORE_OPENGL_MODULE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore-opengl-module+=	qore-opengl-module>=0.0.3
BUILDLINK_ABI_DEPENDS.qore-opengl-module?=	qore-opengl-module>=0.0.3nb8
BUILDLINK_PKGSRCDIR.qore-opengl-module?=	../../graphics/qore-opengl-module

.include "../../lang/qore/buildlink3.mk"
.endif	# QORE_OPENGL_MODULE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore-opengl-module
