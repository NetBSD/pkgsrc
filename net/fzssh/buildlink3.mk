# $NetBSD: buildlink3.mk,v 1.1 2026/05/15 07:41:33 wiz Exp $

BUILDLINK_TREE+=	fzssh

.if !defined(FZSSH_BUILDLINK3_MK)
FZSSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fzssh+=	fzssh>=1.2.1
BUILDLINK_PKGSRCDIR.fzssh?=	../../net/fzssh

.include "../../net/libfilezilla/buildlink3.mk"
.endif	# FZSSH_BUILDLINK3_MK

BUILDLINK_TREE+=	-fzssh
