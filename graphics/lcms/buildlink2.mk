# $NetBSD: buildlink2.mk,v 1.4 2004/02/09 12:03:27 seb Exp $

.if !defined(LCMS_BUILDLINK2_MK)
LCMS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		lcms
BUILDLINK_DEPENDS.lcms?=	lcms>=1.06
BUILDLINK_PKGSRCDIR.lcms?=	../../graphics/lcms

EVAL_PREFIX+=	BUILDLINK_PREFIX.lcms=lcms
BUILDLINK_PREFIX.lcms_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.lcms=	include/icc34.h
BUILDLINK_FILES.lcms+=	include/lcms.h
BUILDLINK_FILES.lcms+=	lib/liblcms.*

BUILDLINK_CPPFLAGS.lcms=	-I${BUILDLINK_PREFIX.lcms}/include

BUILDLINK_TARGETS+=	lcms-buildlink
BUILDLINK_TARGETS+=	buildlink-include-lcms

lcms-buildlink: _BUILDLINK_USE

buildlink-include-lcms: .PHONY
.for _h_ in lcms.h icc34.h
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${BUILDLINK_DIR}/include/lcms/${_h_} ]; then		\
		${INSTALL_DATA_DIR} ${BUILDLINK_DIR}/include/lcms;	\
		${ECHO_BUILDLINK_MSG} "Linking lcms/${_h_} to ${_h_} in ${BUILDLINK_DIR}/include"; \
		${LN} -s ${BUILDLINK_PREFIX.lcms}/include/${_h_} ${BUILDLINK_DIR}/include/lcms/${_h_}; \
	fi
.endfor

.endif	# LCMS_BUILDLINK2_MK
