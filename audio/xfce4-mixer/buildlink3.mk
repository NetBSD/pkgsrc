# $NetBSD: buildlink3.mk,v 1.25 2009/09/16 01:15:33 reed Exp $

BUILDLINK_TREE+=	xfce4-mixer

.if !defined(XFCE4_MIXER_BUILDLINK3_MK)
XFCE4_MIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-mixer+=	xfce4-mixer>=4.6.0
BUILDLINK_PKGSRCDIR.xfce4-mixer?=	../../audio/xfce4-mixer

.endif # XFCE4_MIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-mixer
