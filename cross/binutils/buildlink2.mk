# $NetBSD: buildlink2.mk,v 1.1 2002/09/30 22:16:48 jlam Exp $

.if !defined(CROSS_BINUTILS_BUILDLINK2_MK)
CROSS_BINUTILS_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.cross-binutils?=	cross-binutils>=2.9.1.1
BUILDLINK_PKGSRCDIR.cross-binutils?=	../../cross/binutils
BUILDLINK_DEPMETHOD.cross-binutils?=	build

BUILDLINK_PACKAGES+=		cross-binutils
BUILDLINK_PREFIX.cross-binutils=	${LOCALBASE}

CROSS=	${CROSSBASE:S/${BUILDLINK_PREFIX.cross-binutils}\///}

BUILDLINK_FILES.cross-binutils+=	${CROSS}/include/ansidecl.h
BUILDLINK_FILES.cross-binutils+=	${CROSS}/include/bfd.h
BUILDLINK_FILES.cross-binutils+=	${CROSS}/include/bfdlink.h
BUILDLINK_FILES.cross-binutils+=	${CROSS}/lib/libbfd.*
BUILDLINK_FILES.cross-binutils+=	${CROSS}/lib/libbfd-*.*
BUILDLINK_FILES.cross-binutils+=	${CROSS}/lib/libiberty.*
BUILDLINK_FILES.cross-binutils+=	${CROSS}/lib/libopcodes.*
BUILDLINK_FILES.cross-binutils+=	${CROSS}/lib/libopcodes-*.*

BUILDLINK_TARGETS+=	cross-binutils-buildlink

cross-binutils-buildlink: _BUILDLINK_USE

.endif	# CROSS_BINUTILS_BUILDLINK2_MK
