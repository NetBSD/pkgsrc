# $NetBSD: buildlink3.mk,v 1.1 2012/07/01 15:27:43 jmmv Exp $

BUILDLINK_TREE+=	atf-libs

.if !defined(ATF_LIBS_BUILDLINK3_MK)
ATF_LIBS_BUILDLINK3_MK:=

# The ATF libraries have not been properly versioned until now because, by
# default, they were only installed as static libraries.  However, for some
# obscure reason, the disabling of shared libraries is not working (at least
# under NetBSD with pkgsrc).  Make sure we use a single API/ABI of the
# abi-libs package to prevent unexpected incompatibilities until the ATF
# libraries provide proper versioning on their own.
BUILDLINK_API_DEPENDS.atf-libs+=	atf-libs>=0.15
BUILDLINK_API_DEPENDS.atf-libs+=	atf-libs<0.16
BUILDLINK_PKGSRCDIR.atf-libs?=		../../devel/atf-libs
.endif	# ATF_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-atf-libs
