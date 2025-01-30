# $NetBSD: buildlink3.mk,v 1.5 2025/01/30 13:26:08 pho Exp $

BUILDLINK_TREE+=	hs-toml-parser

.if !defined(HS_TOML_PARSER_BUILDLINK3_MK)
HS_TOML_PARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-toml-parser+=	hs-toml-parser>=2.0.1
BUILDLINK_ABI_DEPENDS.hs-toml-parser+=	hs-toml-parser>=2.0.1.0
BUILDLINK_PKGSRCDIR.hs-toml-parser?=	../../textproc/hs-toml-parser

.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.endif	# HS_TOML_PARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-toml-parser
