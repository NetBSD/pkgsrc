# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:11:39 jlam Exp $
#
# This Makefile fragment is included by packages that use esound.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.esound to the dependency pattern
#     for the version of esound desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(ESOUND_BUILDLINK2_MK)
ESOUND_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.esound?=	esound>=0.2.18
DEPENDS+=			${BUILDLINK_DEPENDS.esound}:../../audio/esound

BUILDLINK_PREFIX.esound=	${LOCALBASE}
BUILDLINK_FILES.esound=		include/esd.h
BUILDLINK_FILES.esound+=	lib/libesd.*

.include "../../audio/libaudiofile/buildlink2.mk"

BUILDLINK_TARGETS+=		esound-buildlink

esound-buildlink: _BUILDLINK_USE

.endif	# ESOUND_BUILDLINK2_MK
