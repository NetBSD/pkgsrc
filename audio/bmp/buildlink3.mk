# $NetBSD: buildlink3.mk,v 1.24 2012/10/08 23:00:44 adam Exp $

BUILDLINK_TREE+=	bmp

.if !defined(BMP_BUILDLINK3_MK)
BMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bmp+=	bmp>=0.9.7rc2nb3
BUILDLINK_ABI_DEPENDS.bmp+=	bmp>=0.9.7.1nb23
BUILDLINK_PKGSRCDIR.bmp?=	../../audio/bmp

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # BMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-bmp
