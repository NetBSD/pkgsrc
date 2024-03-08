# $NetBSD: buildlink3.mk,v 1.1 2024/03/08 12:02:33 wiz Exp $

BUILDLINK_TREE+=	gcc13-gnat

.if !defined(GCC13_GNAT_BUILDLINK3_MK)
GCC13_GNAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc13-gnat+=	gcc13-gnat>=13
BUILDLINK_ABI_DEPENDS.gcc13-gnat+=	gcc13-gnat>=13.2
BUILDLINK_PKGSRCDIR.gcc13-gnat=		../../lang/gcc13-gnat
BUILDLINK_DEPMETHOD.gcc13-gnat?=	build

ADALIB_PREFIX=	gcc13-gnat/lib/gcc/${MACHINE_ARCH}-${LOWER_VENDOR}-${LOWER_OPSYS}/${GCC13_DIST_VERSION}

BUILDLINK_FILES.gcc13-gnat+=	${ADALIB_PREFIX}/adalib/*.ali

BUILDLINK_INCDIRS.gcc13-gnat+=	gcc13-gnat/include ${ADALIB_PREFIX}/adainclude
BUILDLINK_LIBDIRS.gcc13-gnat+=	gcc13-gnat/lib ${ADALIB_PREFIX}/adalib

pkgbase := gcc13-gnat
.include "../../mk/pkg-build-options.mk"
.endif

BUILDLINK_TREE+=	-gcc13-gnat
