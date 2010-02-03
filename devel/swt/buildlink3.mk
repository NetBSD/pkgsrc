# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/02/03 13:51:29 jmcneill Exp $

BUILDLINK_TREE+=	swt

.if !defined(SWT_BUILDLINK3_MK)
SWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swt+=	swt>=3.5.1.3555
BUILDLINK_PKGSRCDIR.swt?=	../../devel/swt

.endif	# SWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-swt
