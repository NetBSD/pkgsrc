# $NetBSD: kpathsea.buildlink2.mk,v 1.2 2003/03/15 08:17:08 kei Exp $

.if !defined(KPATHSEA_BUILDLINK2_MK)
KPATHSEA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		kpathsea
BUILDLINK_DEPENDS.kpathsea?=	teTeX2-bin>=2.0.1
BUILDLINK_PKGSRCDIR.kpathsea?=	../../print/teTeX2-bin
BUILDLINK_DEPMETHOD.kpathsea?=	build

EVAL_PREFIX+=		BUILDLINK_PREFIX.kpathsea=teTeX2-bin
BUILDLINK_PREFIX.kpathsea_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kpathsea=	include/kpathsea/*
BUILDLINK_FILES.kpathsea+=	lib/libkpathsea.*

BUILDLINK_TARGETS+=	kpathsea-buildlink

kpathsea-buildlink: _BUILDLINK_USE

.endif	# KPATHSEA_BUILDLINK2_MK
