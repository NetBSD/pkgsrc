# $NetBSD: buildlink3.mk,v 1.2 2026/06/09 17:57:02 wiz Exp $

BUILDLINK_TREE+=	fzssh

.if !defined(FZSSH_BUILDLINK3_MK)
FZSSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fzssh+=	fzssh>=1.2.1
BUILDLINK_ABI_DEPENDS.fzssh+=	fzssh>=1.3.0
BUILDLINK_PKGSRCDIR.fzssh?=	../../net/fzssh

.include "../../net/libfilezilla/buildlink3.mk"
.endif	# FZSSH_BUILDLINK3_MK

BUILDLINK_TREE+=	-fzssh
