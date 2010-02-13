# $NetBSD: buildlink3.mk,v 1.1 2010/02/13 16:13:52 tnn Exp $

BUILDLINK_TREE+=	clang

.if !defined(CLANG_BUILDLINK3_MK)
CLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clang+=	clang>=2.6nb2
BUILDLINK_PKGSRCDIR.clang?=	../../lang/clang

.endif	# CLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-clang
