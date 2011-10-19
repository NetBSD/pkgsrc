# $NetBSD: buildlink3.mk,v 1.15 2011/10/19 06:13:02 obache Exp $

BUILDLINK_TREE+=	usrp

.if !defined(USRP_BUILDLINK3_MK)
USRP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.usrp+=	usrp>=3.0.4
BUILDLINK_ABI_DEPENDS.usrp?=	usrp>=3.3.0nb1
BUILDLINK_PKGSRCDIR.usrp?=	../../ham/usrp

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.endif # USRP_BUILDLINK3_MK

BUILDLINK_TREE+=	-usrp
