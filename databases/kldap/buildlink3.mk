# $NetBSD: buildlink3.mk,v 1.32 2026/09/29 06:04:12 wiz Exp $

BUILDLINK_TREE+=	kldap

.if !defined(KLDAP_BUILDLINK3_MK)
KLDAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kldap+=	kldap>=25.08.2
BUILDLINK_ABI_DEPENDS.kldap?=	kldap>=26.08.0nb2
BUILDLINK_PKGSRCDIR.kldap?=	../../databases/kldap

.include "../../textproc/kf6-kcompletion/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KLDAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-kldap
