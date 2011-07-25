# $NetBSD: buildlink3.mk,v 1.2 2011/07/25 17:53:17 jakllsch Exp $

BUILDLINK_TREE+=	lcms2

.if !defined(LCMS2_BUILDLINK3_MK)
LCMS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lcms2+=	lcms2>=2.2
BUILDLINK_PKGSRCDIR.lcms2?=	../../graphics/lcms2

BUILDLINK_TARGETS+=	buildlink-include-lcms2

.PHONY: buildlink-include-lcms2
buildlink-include-lcms2:
.for _h_ in lcms2.h
	${RUN}								\
	if [ ! -f ${BUILDLINK_DIR}/include/lcms2/${_h_} ]; then		\
		${MKDIR} ${BUILDLINK_DIR}/include/lcms2;		\
		${ECHO_BUILDLINK_MSG} "Linking lcms2/${_h_} to ${_h_} in ${BUILDLINK_DIR}/include"; \
		${LN} -s ${BUILDLINK_PREFIX.lcms2}/include/${_h_} ${BUILDLINK_DIR}/include/lcms2/${_h_}; \
	fi
.endfor
.endif # LCMS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-lcms2
