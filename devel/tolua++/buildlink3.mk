# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/05/08 09:34:17 imil Exp $

BUILDLINK_TREE+=	toluapp

.if !defined(TOLUAPP_BUILDLINK3_MK)
TOLUAPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.toluapp+=	tolua++>=1.0.93
BUILDLINK_PKGSRCDIR.toluapp?=	../../devel/tolua++

.include "../../lang/lua/buildlink3.mk"
.endif	# TOLUAPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-toluapp
