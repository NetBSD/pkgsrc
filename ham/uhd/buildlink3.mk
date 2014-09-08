# $NetBSD: buildlink3.mk,v 1.1 2014/09/08 07:12:05 mef Exp $

BUILDLINK_TREE+=        uhd

.if !defined(UHD_BUILDLINK3_MK)
UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uhd+=    uhd>=2.22
BUILDLINK_PKGSRCDIR.uhd?=              ../../ham/uhd
.endif # UHD_BUILDLINK3_MK

BUILDLINK_TREE+=        -uhd
