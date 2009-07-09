# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/07/09 19:44:50 drochner Exp $

BUILDLINK_TREE+=	lensfun

.if !defined(LENSFUN_BUILDLINK3_MK)
LENSFUN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lensfun+=	lensfun>=0.2.2b
BUILDLINK_PKGSRCDIR.lensfun?=	../../graphics/lensfun

.include "../../devel/glib2/buildlink3.mk"
.endif # LENSFUN_BUILDLINK3_MK

BUILDLINK_TREE+=	-lensfun
