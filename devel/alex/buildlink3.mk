# $NetBSD: buildlink3.mk,v 1.2 2015/05/09 11:22:25 szptvlfn Exp $

BUILDLINK_TREE+=	alex

.if !defined(ALEX_BUILDLINK3_MK)
ALEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alex+=	alex>=3.1.4
BUILDLINK_ABI_DEPENDS.alex+=	alex>=3.1.4nb1
BUILDLINK_PKGSRCDIR.alex?=	../../devel/alex
BUILDLINK_DEPMETHOD.alex?=	build

.include "../../devel/hs-QuickCheck/buildlink3.mk"
.endif	# ALEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-alex
