# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:17 pho Exp $

BUILDLINK_TREE+=	idris

.if !defined(IDRIS_BUILDLINK3_MK)
IDRIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.idris+=	idris>=1.3.2
BUILDLINK_ABI_DEPENDS.idris+=	idris>=1.3.3nb3
BUILDLINK_PKGSRCDIR.idris?=	../../lang/idris

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-annotated-wl-pprint/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-ansi-wl-pprint/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../textproc/hs-cheapskate/buildlink3.mk"
.include "../../devel/hs-code-page/buildlink3.mk"
.include "../../devel/hs-fingertree/buildlink3.mk"
.include "../../devel/hs-fsnotify/buildlink3.mk"
.include "../../math/hs-ieee754/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-terminal-size/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-vector-binary-instances/buildlink3.mk"
.include "../../archivers/hs-zip-archive/buildlink3.mk"
.endif	# IDRIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-idris
