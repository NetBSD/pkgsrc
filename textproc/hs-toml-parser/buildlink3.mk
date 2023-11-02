# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:37:39 pho Exp $

BUILDLINK_TREE+=	hs-toml-parser

.if !defined(HS_TOML_PARSER_BUILDLINK3_MK)
HS_TOML_PARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-toml-parser+=	hs-toml-parser>=1.3.0
BUILDLINK_ABI_DEPENDS.hs-toml-parser+=	hs-toml-parser>=1.3.0.0nb1
BUILDLINK_PKGSRCDIR.hs-toml-parser?=	../../textproc/hs-toml-parser

.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.endif	# HS_TOML_PARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-toml-parser
