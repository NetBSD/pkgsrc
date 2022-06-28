# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:34:09 wiz Exp $

BUILDLINK_TREE+=	osmo-sdr

.if !defined(OSMO_SDR_BUILDLINK3_MK)
OSMO_SDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.osmo-sdr+=	osmo-sdr>=0.1
BUILDLINK_ABI_DEPENDS.osmo-sdr+=	osmo-sdr>=0.1nb7
BUILDLINK_PKGSRCDIR.osmo-sdr?=		../../ham/osmo-sdr
.endif # OSMO_SDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-osmo-sdr
