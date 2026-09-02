# $NetBSD: buildlink3.mk,v 1.7 2026/09/02 19:04:22 wiz Exp $

BUILDLINK_TREE+=	accountsservice

.if !defined(ACCOUNTSSERVICE_BUILDLINK3_MK)
ACCOUNTSSERVICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.accountsservice+=	accountsservice>=0.6.40
BUILDLINK_ABI_DEPENDS.accountsservice?=	accountsservice>=0.6.42nb7
BUILDLINK_PKGSRCDIR.accountsservice?=	../../sysutils/accountsservice

.include "../../security/polkit/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# ACCOUNTSSERVICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-accountsservice
