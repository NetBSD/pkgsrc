# $NetBSD: buildlink2.mk,v 1.1 2002/10/02 19:51:52 jlam Exp $

.if !defined(PVM_BUILDLINK2_MK)
PVM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		pvm
BUILDLINK_DEPENDS.pvm?=		pvm>=3.4.3
BUILDLINK_PKGSRCDIR.pvm?=	../../parallel/pvm3

.include "${BUILDLINK_PKGSRCDIR.pvm}/arch.mk"

EVAL_PREFIX+=	BUILDLINK_PREFIX.pvm=pvm
BUILDLINK_PREFIX.pvm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pvm=	pvm3/include/*.h
BUILDLINK_FILES.pvm+=	pvm3/lib/${PVM_ARCH}/libfpvm3.*
BUILDLINK_FILES.pvm+=	pvm3/lib/${PVM_ARCH}/libgpvm3.*
BUILDLINK_FILES.pvm+=	pvm3/lib/${PVM_ARCH}/libpvm3.*
BUILDLINK_FILES.pvm+=	pvm3/lib/${PVM_ARCH}/libpvmtrc.*

BUILDLINK_CPPFLAGS.pvm=	-I${BUILDLINK_PREFIX.pvm}/pvm3/include
BUILDLINK_LDFLAGS.pvm=	-L${BUILDLINK_PREFIX.pvm}/pvm3/lib/${PVM_ARCH}

BUILDLINK_TARGETS+=	pvm-buildlink

pvm-buildlink: _BUILDLINK_USE

.endif	# PVM_BUILDLINK2_MK
