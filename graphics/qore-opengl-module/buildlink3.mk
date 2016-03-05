# $NetBSD: buildlink3.mk,v 1.2 2016/03/05 11:27:50 jperkin Exp $
#

BUILDLINK_TREE+=	qore-opengl-module

.if !defined(QORE_OPENGL_MODULE_BUILDLINK3_MK)
QORE_OPENGL_MODULE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore-opengl-module+=	qore-opengl-module>=0.0.3
BUILDLINK_ABI_DEPENDS.qore-opengl-module?=	qore-opengl-module>=0.0.3nb6
BUILDLINK_PKGSRCDIR.qore-opengl-module?=	../../graphics/qore-opengl-module

.include "../../lang/qore/buildlink3.mk"
.endif	# QORE_OPENGL_MODULE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore-opengl-module
