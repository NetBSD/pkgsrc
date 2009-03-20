# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:41 joerg Exp $

BUILDLINK_TREE+=	lcms

.if !defined(LCMS_BUILDLINK3_MK)
LCMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lcms+=	lcms>=1.06
BUILDLINK_ABI_DEPENDS.lcms+=	lcms>=1.12nb2
BUILDLINK_PKGSRCDIR.lcms?=	../../graphics/lcms

BUILDLINK_TARGETS+=	buildlink-include-lcms

.PHONY: buildlink-include-lcms
buildlink-include-lcms:
.for _h_ in lcms.h icc34.h
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${BUILDLINK_DIR}/include/lcms/${_h_} ]; then		\
		${MKDIR} ${BUILDLINK_DIR}/include/lcms;	\
		${ECHO_BUILDLINK_MSG} "Linking lcms/${_h_} to ${_h_} in ${BUILDLINK_DIR}/include"; \
		${LN} -s ${BUILDLINK_PREFIX.lcms}/include/${_h_} ${BUILDLINK_DIR}/include/lcms/${_h_}; \
	fi
.endfor
.endif # LCMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-lcms
