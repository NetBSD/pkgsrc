# $NetBSD: buildlink3.mk,v 1.1 2026/10/05 13:10:41 ktnb Exp $

BUILDLINK_TREE+=	usrsctp

.if !defined(USRSCTP_BUILDLINK3_MK)
USRSCTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.usrsctp+=	usrsctp>=0.9.5.0
BUILDLINK_PKGSRCDIR.usrsctp?=	../../net/usrsctp

BUILDLINK_DEPMETHOD.usrsctp?=	build
.endif	# USRSCTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-usrsctp
