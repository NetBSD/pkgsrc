# $NetBSD: buildlink3.mk,v 1.2 2021/08/17 08:02:50 wiz Exp $

BUILDLINK_TREE+=	qr-code-generator

.if !defined(QR_CODE_GENERATOR_BUILDLINK3_MK)
QR_CODE_GENERATOR_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.qr-code-generator?=	build

BUILDLINK_API_DEPENDS.qr-code-generator+=	qr-code-generator>=1.7.0
BUILDLINK_PKGSRCDIR.qr-code-generator?=		../../graphics/qr-code-generator
.endif	# QR_CODE_GENERATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-qr-code-generator
