# $NetBSD: buildlink3.mk,v 1.3 2004/02/09 12:03:27 seb Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LCMS_BUILDLINK3_MK:=	${LCMS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	lcms
.endif

.if !empty(LCMS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		lcms
BUILDLINK_DEPENDS.lcms+=	lcms>=1.06
BUILDLINK_PKGSRCDIR.lcms?=	../../graphics/lcms
.endif # LCMS_BUILDLINK3_MK

BUILDLINK_TARGETS+=	buildlink-include-lcms

buildlink-include-lcms: .PHONY
.for _h_ in lcms.h icc34.h
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${BUILDLINK_DIR}/include/lcms/${_h_} ]; then		\
		${INSTALL_DATA_DIR} ${BUILDLINK_DIR}/include/lcms;	\
		${ECHO_BUILDLINK_MSG} "Linking lcms/${_h_} to ${_h_} in ${BUILDLINK_DIR}/include"; \
		${LN} -s ${BUILDLINK_PREFIX.lcms}/include/${_h_} ${BUILDLINK_DIR}/include/lcms/${_h_}; \
	fi
.endfor

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
