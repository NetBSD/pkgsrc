# $NetBSD: buildlink2.mk,v 1.1 2002/10/25 12:22:58 wiz Exp $
#

.if !defined(NESSUS_CORE_BUILDLINK2_MK)
NESSUS_CORE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			nessus-core
BUILDLINK_DEPENDS.nessus-core?=		nessus-core>=1.2.6
BUILDLINK_PKGSRCDIR.nessus-core?=	../../security/nessus-core

EVAL_PREFIX+=	BUILDLINK_PREFIX.nessus-core=nessus-core
BUILDLINK_PREFIX.nessus-core_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.nessus-core+=	include/nessus/config.h
BUILDLINK_FILES.nessus-core+=	include/nessus/includes.h
BUILDLINK_FILES.nessus-core+=	include/nessus/nessus-devel.h
BUILDLINK_FILES.nessus-core+=	include/nessus/nessusicmp.h
BUILDLINK_FILES.nessus-core+=	include/nessus/nessusip.h
BUILDLINK_FILES.nessus-core+=	include/nessus/nessusraw.h
BUILDLINK_FILES.nessus-core+=	include/nessus/nessustcp.h
BUILDLINK_FILES.nessus-core+=	include/nessus/nessusudp.h
BUILDLINK_FILES.nessus-core+=	include/nessus/ntcompat.h

.include "../../security/libnasl/buildlink2.mk"
.include "../../security/nessus-libraries/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	nessus-core-buildlink

nessus-core-buildlink: _BUILDLINK_USE

.endif	# NESSUS_CORE_BUILDLINK2_MK
