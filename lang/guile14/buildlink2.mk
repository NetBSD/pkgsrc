# $NetBSD: buildlink2.mk,v 1.4 2003/01/16 02:20:47 uebayasi Exp $

.if !defined(GUILE14_BUILDLINK2_MK)
GUILE14_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		guile14
BUILDLINK_DEPENDS.guile14?=	guile14>=1.4nb1
BUILDLINK_PKGSRCDIR.guile14?=	../../lang/guile14

# Put only 'bin/guile' and 'bin/guild-config' at ${BUILDLINK_DIR}
_GUILE14_BIN=		${BUILDLINK_PREFIX.guile14}/guile/1.4/bin/guile
_GUILE14_BUILDLINK_BIN=	${BUILDLINK_DIR}/bin/guile
_GUILE14_CONFIG=	${BUILDLINK_PREFIX.guile14}/guile/1.4/bin/guile-config
_GUILE14_BUILDLINK_CONFIG=	${BUILDLINK_DIR}/bin/guile-config

EVAL_PREFIX+=				BUILDLINK_PREFIX.guile14=guile14
BUILDLINK_PREFIX.guile14=		${LOCALBASE}
BUILDLINK_PREFIX.guile14_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.guile14+=		guile/1.4/include/libguile.*
BUILDLINK_FILES.guile14+=		guile/1.4/include/guile/*
BUILDLINK_FILES.guile14+=		guile/1.4/include/guile-readline/*
BUILDLINK_FILES.guile14+=		guile/1.4/include/libguile/*
BUILDLINK_FILES.guile14+=		guile/1.4/lib/libguile.*
BUILDLINK_FILES.guile14+=		guile/1.4/lib/libguilereadline.*

USE_GNU_READLINE=	# defined

.include "../../devel/libtool/buildlink2.mk"	# For Librtdl
.include "../../devel/readline/buildlink2.mk"

BUILDLINK_TARGETS+=	guile14-buildlink
BUILDLINK_TARGETS+=	guile14-buildlink-config

guile14-buildlink: _BUILDLINK_USE

guile14-buildlink-config:
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_BUILDLINK_MSG} "Linking executable ${_GUILE14_BUILDLINK_BIN}."
	${_PKG_SILENT}${_PKG_DEBUG}${LN} -s ${_GUILE14_BIN} ${_GUILE14_BUILDLINK_BIN}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_BUILDLINK_MSG} "Linking config script ${_GUILE14_BUILDLINK_CONFIG}."
	${_PKG_SILENT}${_PKG_DEBUG}${LN} -s ${_GUILE14_CONFIG} ${_GUILE14_BUILDLINK_CONFIG}

.endif	# GUILE14_BUILDLINK2_MK
