# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:30 joerg Exp $

BUILDLINK_TREE+=	tre

.if !defined(TRE_BUILDLINK3_MK)
TRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tre+=		tre>=0.7.2
BUILDLINK_PKGSRCDIR.tre?=		../../devel/tre
BUILDLINK_CPPFLAGS.tre+=		-I${BUILDLINK_PREFIX.tre}/include/tre
.endif # TRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-tre
