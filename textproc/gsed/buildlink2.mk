# $NetBSD: buildlink2.mk,v 1.1.2.2 2003/06/18 23:59:20 grant Exp $

.if !defined(GSED_BUILDLINK2_MK)
GSED_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gsed
BUILDLINK_DEPENDS.gsed?=	gsed>=3.02
BUILDLINK_PKGSRCDIR.gsed?=	../../textproc/gsed
BUILDLINK_DEPMETHOD.gsed=	build

EVAL_PREFIX+=	BUILDLINK_PREFIX.gsed=gsed
BUILDLINK_PREFIX.gsed_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gsed=		bin/${GNU_PROGRAM_PREFIX}sed

BUILDLINK_TARGETS+=	gsed-buildlink gsed-buildlink-bin

gsed-buildlink: _BUILDLINK_USE

gsed-buildlink-bin:
	${_PKG_SILENT}${_PKG_DEBUG}				\
	cd ${BUILDLINK_DIR}/bin;				\
	if [ ! -f sed ]; then					\
	  ${LN} -fs ${GNU_PROGRAM_PREFIX}sed sed ;		\
	fi

.endif	# GSED_BUILDLINK2_MK
