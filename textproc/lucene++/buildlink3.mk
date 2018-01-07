# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:34 rillig Exp $

BUILDLINK_TREE+=	lucene++

.if !defined(LUCENE++_BUILDLINK3_MK)
LUCENE++_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lucene+++=	lucene++>=3.0.7
BUILDLINK_PKGSRCDIR.lucene++?=		../../textproc/lucene++

.endif	# LUCENE++_BUILDLINK3_MK

BUILDLINK_TREE+=	-lucene++
