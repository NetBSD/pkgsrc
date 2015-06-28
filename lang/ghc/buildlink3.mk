# $NetBSD: buildlink3.mk,v 1.15 2015/06/28 16:32:25 joerg Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=6.8.3<7
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=6.8.3nb2<7
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc

BUILDLINK_DEPMETHOD.ghc?=	build

.include "../../devel/readline/buildlink3.mk"
.endif # GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc

# We include gmp/buildlink3.mk here so that "gmp" is registered as a
# direct dependency for any package that includes this buildlink3.mk
# to get ghc as a build dependency.  This is needed since software
# built by ghc requires routines from the "gmp" shared library.
#
.include "../../devel/gmp/buildlink3.mk"
