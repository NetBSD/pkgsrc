# $NetBSD: buildlink3.mk,v 1.3 2015/12/13 14:14:35 szptvlfn Exp $

BUILDLINK_TREE+=	alex

.if !defined(ALEX_BUILDLINK3_MK)
ALEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alex+=	alex>=3.1.4
BUILDLINK_ABI_DEPENDS.alex+=	alex>=3.1.4nb2
BUILDLINK_PKGSRCDIR.alex?=	../../devel/alex
BUILDLINK_DEPMETHOD.alex?=	build

.include "../../devel/hs-QuickCheck/buildlink3.mk"
.endif	# ALEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-alex
