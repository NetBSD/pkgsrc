# $NetBSD: buildlink3.mk,v 1.3 2026/08/21 12:34:05 wiz Exp $

BUILDLINK_TREE+=	fzssh

.if !defined(FZSSH_BUILDLINK3_MK)
FZSSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fzssh+=	fzssh>=1.2.1
BUILDLINK_ABI_DEPENDS.fzssh+=	fzssh>=1.4.0
BUILDLINK_PKGSRCDIR.fzssh?=	../../net/fzssh

.include "../../net/libfilezilla/buildlink3.mk"
.endif	# FZSSH_BUILDLINK3_MK

BUILDLINK_TREE+=	-fzssh
