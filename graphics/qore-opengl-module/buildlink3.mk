# $NetBSD: buildlink3.mk,v 1.5 2018/01/28 16:24:10 wiz Exp $
#

BUILDLINK_TREE+=	qore-opengl-module

.if !defined(QORE_OPENGL_MODULE_BUILDLINK3_MK)
QORE_OPENGL_MODULE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore-opengl-module+=	qore-opengl-module>=0.0.3
BUILDLINK_ABI_DEPENDS.qore-opengl-module?=	qore-opengl-module>=0.0.3nb9
BUILDLINK_PKGSRCDIR.qore-opengl-module?=	../../graphics/qore-opengl-module

.include "../../lang/qore/buildlink3.mk"
.endif	# QORE_OPENGL_MODULE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore-opengl-module
