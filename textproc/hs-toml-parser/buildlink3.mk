# $NetBSD: buildlink3.mk,v 1.4 2024/05/09 01:32:48 pho Exp $

BUILDLINK_TREE+=	hs-toml-parser

.if !defined(HS_TOML_PARSER_BUILDLINK3_MK)
HS_TOML_PARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-toml-parser+=	hs-toml-parser>=2.0.0
BUILDLINK_ABI_DEPENDS.hs-toml-parser+=	hs-toml-parser>=2.0.0.0nb1
BUILDLINK_PKGSRCDIR.hs-toml-parser?=	../../textproc/hs-toml-parser

.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.endif	# HS_TOML_PARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-toml-parser
