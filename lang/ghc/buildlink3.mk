# $NetBSD: buildlink3.mk,v 1.12 2009/05/20 00:58:19 wiz Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=6.8.3
BUILDLINK_ABI_DEPENDS.ghc?=	ghc>=6.8.3nb1
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
