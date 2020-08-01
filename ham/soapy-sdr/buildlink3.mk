# $NetBSD: buildlink3.mk,v 1.1 2020/08/01 07:46:14 tnn Exp $

BUILDLINK_TREE+=	soapy-sdr

.if !defined(SOAPY_SDR_BUILDLINK3_MK)
SOAPY_SDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.soapy-sdr+=	soapy-sdr>=0.7.2
BUILDLINK_PKGSRCDIR.soapy-sdr?=		../../ham/soapy-sdr

#.include "../../devel/boost-libs/buildlink3.mk"
.endif	# SOAPY_SDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-soapy-sdr
