# $NetBSD: buildlink2.mk,v 1.3 2003/10/18 11:53:48 grant Exp $

.if !defined(CDPARANOIA_BUILDLINK2_MK)
CDPARANOIA_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
BUILDLINK_PACKAGES+=			cdparanoia
BUILDLINK_DEPENDS.cdparanoia?=		cdparanoia>=3.0
BUILDLINK_PKGSRCDIR.cdparanoia?=	../../audio/cdparanoia

EVAL_PREFIX+=	BUILDLINK_PREFIX.cdparanoia=cdparanoia
BUILDLINK_PREFIX.cdparanoia_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cdparanoia=	include/cdparanoia/*
BUILDLINK_FILES.cdparanoia+=	lib/libcdda_paranoia.*
BUILDLINK_FILES.cdparanoia+=	lib/libcdda_interface.*

BUILDLINK_TARGETS+=	cdparanoia-buildlink

cdparanoia-buildlink: _BUILDLINK_USE
.endif	# OPSYS == Linux || NetBSD

.endif	# CDPARANOIA_BUILDLINK2_MK
