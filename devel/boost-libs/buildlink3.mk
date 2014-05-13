# $NetBSD: buildlink3.mk,v 1.32 2014/05/13 18:48:49 ryoon Exp $

BUILDLINK_TREE+=	boost-libs

.if !defined(BOOST_LIBS_BUILDLINK3_MK)
BOOST_LIBS_BUILDLINK3_MK:=

# Use a dependency pattern that guarantees the proper ABI.
BUILDLINK_API_DEPENDS.boost-libs+=	boost-libs-1.55.*
BUILDLINK_ABI_DEPENDS.boost-libs?=	boost-libs>=1.55.0
BUILDLINK_PKGSRCDIR.boost-libs?=	../../devel/boost-libs

.include "../../mk/bsd.prefs.mk"
# OpenBSD's gcc 4.2.1 is not sufficient, and gcc46 is minimal pkgsrc gcc
# for OpenBSD. Avoid warning as error.
.if ${OPSYS} == "OpenBSD"
GCC_REQD+=	4.6
.endif

.include "../../devel/boost-headers/buildlink3.mk"
.endif # BOOST_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-boost-libs
