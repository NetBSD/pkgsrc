# $NetBSD: buildlink3.mk,v 1.51 2024/10/20 14:03:20 wiz Exp $

BUILDLINK_TREE+=	bmp

.if !defined(BMP_BUILDLINK3_MK)
BMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bmp+=	bmp>=0.9.7rc2nb3
BUILDLINK_ABI_DEPENDS.bmp+=	bmp>=0.9.7.1nb68
BUILDLINK_PKGSRCDIR.bmp?=	../../audio/bmp

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # BMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-bmp
