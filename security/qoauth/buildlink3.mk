# $NetBSD: buildlink3.mk,v 1.19 2023/11/12 13:23:27 wiz Exp $

BUILDLINK_TREE+=	qoauth

.if !defined(QOAUTH_BUILDLINK3_MK)
QOAUTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qoauth+=	qoauth>=1.0.1
BUILDLINK_ABI_DEPENDS.qoauth?=	qoauth>=1.0.1nb19
BUILDLINK_PKGSRCDIR.qoauth?=	../../security/qoauth

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.endif	# QOAUTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-qoauth
