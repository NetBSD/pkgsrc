# $NetBSD: buildlink3.mk,v 1.9 2010/12/28 08:40:16 obache Exp $

BUILDLINK_TREE+=	tre

.if !defined(TRE_BUILDLINK3_MK)
TRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tre+=		tre>=0.7.2
BUILDLINK_PKGSRCDIR.tre?=		../../devel/tre
BUILDLINK_CPPFLAGS.tre+=		-I${BUILDLINK_PREFIX.tre}/include/tre

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # TRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-tre
