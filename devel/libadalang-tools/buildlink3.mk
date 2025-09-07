# $NetBSD: buildlink3.mk,v 1.1 2025/09/07 07:20:48 dkazankov Exp $

BUILDLINK_TREE+=	libadalang-tools

.if !defined(LIBADALANG_TOOLS_BUILDLINK3_MK)
LIBADALANG_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libadalang-tools+=	libadalang-tools>=25.0.0
BUILDLINK_PKGSRCDIR.libadalang-tools?=		../../devel/libadalang-tools
BUILDLINK_DEPMETHOD.libadalang-tools?=		build

BUILDLINK_CONTENTS_FILTER.libadalang-tools=	\
	${EGREP} "bin/.*$$"

.endif

BUILDLINK_TREE+=	-libadalang-tools
