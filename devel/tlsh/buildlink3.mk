# $NetBSD: buildlink3.mk,v 1.1 2015/12/02 17:22:18 wiz Exp $

BUILDLINK_TREE+=	tlsh

.if !defined(TLSH_BUILDLINK3_MK)
TLSH_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.tlsh?=	build
BUILDLINK_API_DEPENDS.tlsh+=	tlsh>=3.4.3
BUILDLINK_PKGSRCDIR.tlsh?=	../../devel/tlsh
.endif	# TLSH_BUILDLINK3_MK

BUILDLINK_TREE+=	-tlsh
