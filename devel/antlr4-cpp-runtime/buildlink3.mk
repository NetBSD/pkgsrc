# $NetBSD: buildlink3.mk,v 1.1 2026/02/09 16:47:00 ryoon Exp $

BUILDLINK_TREE+=	antlr4-cpp-runtime

.if !defined(ANTLR4_CPP_RUNTIME_BUILDLINK3_MK)
ANTLR4_CPP_RUNTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.antlr4-cpp-runtime+=	antlr4-cpp-runtime>=4.13.2
BUILDLINK_PKGSRCDIR.antlr4-cpp-runtime?=	../../devel/antlr4-cpp-runtime
.endif	# ANTLR4_CPP_RUNTIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-antlr4-cpp-runtime
