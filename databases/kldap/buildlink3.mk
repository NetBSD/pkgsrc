# $NetBSD: buildlink3.mk,v 1.8 2020/11/05 09:06:45 ryoon Exp $

BUILDLINK_TREE+=	kldap

.if !defined(KLDAP_BUILDLINK3_MK)
KLDAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kldap+=	kldap>=17.12.1
BUILDLINK_ABI_DEPENDS.kldap?=	kldap>=20.04.1nb3
BUILDLINK_PKGSRCDIR.kldap?=	../../databases/kldap

.include "../../textproc/kcompletion/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KLDAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-kldap
