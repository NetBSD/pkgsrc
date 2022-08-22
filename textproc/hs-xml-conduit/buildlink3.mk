# $NetBSD: buildlink3.mk,v 1.7 2022/08/22 10:13:25 wiz Exp $

BUILDLINK_TREE+=	hs-xml-conduit

.if !defined(HS_XML_CONDUIT_BUILDLINK3_MK)
HS_XML_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-xml-conduit+=	hs-xml-conduit>=1.9.1
BUILDLINK_ABI_DEPENDS.hs-xml-conduit+=	hs-xml-conduit>=1.9.1.1nb6
BUILDLINK_PKGSRCDIR.hs-xml-conduit?=	../../textproc/hs-xml-conduit

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../textproc/hs-xml-types/buildlink3.mk"
.endif	# HS_XML_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-xml-conduit
