# $NetBSD: buildlink3.mk,v 1.41 2020/03/08 16:47:24 wiz Exp $

BUILDLINK_TREE+=	bmp

.if !defined(BMP_BUILDLINK3_MK)
BMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bmp+=	bmp>=0.9.7rc2nb3
BUILDLINK_ABI_DEPENDS.bmp+=	bmp>=0.9.7.1nb49
BUILDLINK_PKGSRCDIR.bmp?=	../../audio/bmp

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # BMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-bmp
