# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/03 19:18:16 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libntlm.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBNTLM_BUILDLINK2_MK)
LIBNTLM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libntlm
BUILDLINK_DEPENDS.libntlm?=		libntlm>=0.3.2
BUILDLINK_PKGSRCDIR.libntlm?=		../../devel/libntlm

EVAL_PREFIX+=	BUILDLINK_PREFIX.libntlm=libntlm
BUILDLINK_PREFIX.libntlm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libntlm+=	include/ntlm.h
BUILDLINK_FILES.libntlm+=	lib/libntlm.*


BUILDLINK_TARGETS+=	libntlm-buildlink

libntlm-buildlink: _BUILDLINK_USE

.endif	# LIBNTLM_BUILDLINK2_MK
