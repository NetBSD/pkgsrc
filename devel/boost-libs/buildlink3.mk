# $NetBSD: buildlink3.mk,v 1.38 2015/12/27 12:41:42 adam Exp $

BUILDLINK_TREE+=	boost-libs

.if !defined(BOOST_LIBS_BUILDLINK3_MK)
BOOST_LIBS_BUILDLINK3_MK:=

# Use a dependency pattern that guarantees the proper ABI.
BUILDLINK_API_DEPENDS.boost-libs+=	boost-libs-1.60.*
BUILDLINK_ABI_DEPENDS.boost-libs?=	boost-libs>=1.60.0
BUILDLINK_PKGSRCDIR.boost-libs?=	../../devel/boost-libs

.include "../../mk/bsd.fast.prefs.mk"
# Sync with meta-pkgs/boost/Makefile.common
.if ${OPSYS} == "OpenBSD"
GCC_REQD+=		4.6
.else
GCC_REQD+=		4.5
.endif

.include "../../devel/boost-headers/buildlink3.mk"
.endif # BOOST_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-boost-libs
