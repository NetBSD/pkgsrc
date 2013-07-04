# $NetBSD: buildlink3.mk,v 1.2 2013/07/04 21:27:57 adam Exp $

BUILDLINK_TREE+=	toluapp

.if !defined(TOLUAPP_BUILDLINK3_MK)
TOLUAPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.toluapp+=	tolua++>=1.0.93
BUILDLINK_ABI_DEPENDS.toluapp?=	tolua++>=1.0.93nb1
BUILDLINK_PKGSRCDIR.toluapp?=	../../devel/tolua++

.include "../../lang/lua/buildlink3.mk"
.endif	# TOLUAPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-toluapp
