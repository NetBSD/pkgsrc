# $NetBSD: buildlink2.mk,v 1.10 2003/07/13 13:52:21 wiz Exp $

.if !defined(GUILE14_BUILDLINK2_MK)
GUILE14_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		guile14
BUILDLINK_DEPENDS.guile14?=	guile14>=1.4.1nb4
BUILDLINK_PKGSRCDIR.guile14?=	../../lang/guile14

EVAL_PREFIX+=			GUILE14_PREFIX=guile14
GUILE14_PREFIX_DEFAULT=		${LOCALBASE}/guile/1.4
BUILDLINK_PREFIX.guile14=	${LOCALBASE}
GUILE14_SUBDIR=			${GUILE14_PREFIX:S/^${BUILDLINK_PREFIX.guile14}\///}
BUILDLINK_FILES.guile14+=	${GUILE14_SUBDIR}/include/libguile.*
BUILDLINK_FILES.guile14+=	${GUILE14_SUBDIR}/include/guile/*
BUILDLINK_FILES.guile14+=	${GUILE14_SUBDIR}/include/guile-readline/*
BUILDLINK_FILES.guile14+=	${GUILE14_SUBDIR}/include/libguile/*
BUILDLINK_FILES.guile14+=	${GUILE14_SUBDIR}/lib/libguile.*
BUILDLINK_FILES.guile14+=	${GUILE14_SUBDIR}/lib/libguilereadline.*

USE_GNU_READLINE=	# defined

.include "../../devel/libtool/buildlink2.mk"	# For libltdl
.include "../../devel/readline/buildlink2.mk"

BUILDLINK_TARGETS+=	guile14-buildlink
BUILDLINK_TARGETS+=	guile14-buildlink-bin
BUILDLINK_TARGETS+=	guile14-buildlink-la

GUILE14=		${GUILE14_PREFIX}/bin/guile
GUILE14_CONFIG=		${GUILE14_PREFIX}/bin/guile-config
GUILE14_SNARF=		${GUILE14_PREFIX}/bin/guile-snarf

guile14-buildlink: _BUILDLINK_USE

# Put only bin/guile, bin/guile-config, and bin/guile-snarf into
# ${BUILDLINK_DIR}/bin.  Other files (headers/libraries) are put in
# ${BUILDLINK_DIR}/guile/1.4/...
#
guile14-buildlink-bin:
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_BUILDLINK_MSG} "Linking Guile executables."
	${_PKG_SILENT}${_PKG_DEBUG}${LN} -s ${GUILE14_PREFIX}/bin/guile* ${BUILDLINK_DIR}/bin

REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_DIR}/bin/guile|${GUILE14_PREFIX}/bin/guile|g"

guile14-buildlink-la:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for file in libguile.la libguilereadline.la; do			\
		src="${GUILE14_PREFIX}/lib/$$file";			\
		dest="${BUILDLINK_DIR}/lib/$$file";			\
		if [ -f $$src ]; then					\
			${ECHO_BUILDLINK_MSG} "Linking $$src to $$dest."; \
			${LN} -sf $$src $$dest;				\
		fi;							\
	done

.endif	# GUILE14_BUILDLINK2_MK
