# $NetBSD: buildlink3.mk,v 1.10 2011/04/22 13:42:07 obache Exp $

BUILDLINK_TREE+=	tre

.if !defined(TRE_BUILDLINK3_MK)
TRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tre+=		tre>=0.7.2
BUILDLINK_ABI_DEPENDS.tre?=		tre>=0.7.6nb2
BUILDLINK_PKGSRCDIR.tre?=		../../devel/tre
BUILDLINK_CPPFLAGS.tre+=		-I${BUILDLINK_PREFIX.tre}/include/tre

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # TRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-tre
