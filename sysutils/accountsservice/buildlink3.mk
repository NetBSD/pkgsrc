# $NetBSD: buildlink3.mk,v 1.8 2026/09/27 11:38:30 tnn Exp $

BUILDLINK_TREE+=	accountsservice

.if !defined(ACCOUNTSSERVICE_BUILDLINK3_MK)
ACCOUNTSSERVICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.accountsservice+=	accountsservice>=0.6.40
BUILDLINK_ABI_DEPENDS.accountsservice?=	accountsservice>=0.6.42nb8
BUILDLINK_PKGSRCDIR.accountsservice?=	../../sysutils/accountsservice

.include "../../security/polkit/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# ACCOUNTSSERVICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-accountsservice
