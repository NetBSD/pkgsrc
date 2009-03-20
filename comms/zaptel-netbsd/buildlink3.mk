# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:03 joerg Exp $

BUILDLINK_TREE+=	zaptel-netbsd

.if !defined(ZAPTEL_NETBSD_BUILDLINK3_MK)
ZAPTEL_NETBSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zaptel-netbsd+=	zaptel-netbsd>=20050314
BUILDLINK_ABI_DEPENDS.zaptel-netbsd?=	zaptel-netbsd>=20060127nb1
BUILDLINK_PKGSRCDIR.zaptel-netbsd?=	../../comms/zaptel-netbsd
BUILDLINK_DEPMETHOD.zaptel-netbsd?=	build

.include "../../devel/newt/buildlink3.mk"
.endif # ZAPTEL_NETBSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-zaptel-netbsd
