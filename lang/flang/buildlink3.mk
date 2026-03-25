# $NetBSD: buildlink3.mk,v 1.5 2026/03/25 22:56:26 wiz Exp $

BUILDLINK_TREE+=	flang

.if !defined(FLANG_BUILDLINK3_MK)
FLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flang+=	flang>=20.1.0
BUILDLINK_PKGSRCDIR.flang?=	../../lang/flang

BUILDLINK_FILES.flang+=		bin/bbc
BUILDLINK_FILES.flang+=		bin/fir-opt
BUILDLINK_FILES.flang+=		bin/flang-new
BUILDLINK_FILES.flang+=		bin/flang-to-external-fc
BUILDLINK_FILES.flang+=		bin/tco

.include "../../lang/llvm/buildlink3.mk"
.endif	# FLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-flang
