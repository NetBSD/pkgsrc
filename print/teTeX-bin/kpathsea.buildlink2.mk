# $NetBSD: kpathsea.buildlink2.mk,v 1.3 2004/03/29 05:05:45 jlam Exp $

.if !defined(KPATHSEA_BUILDLINK2_MK)
KPATHSEA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		kpathsea
BUILDLINK_PKGBASE.kpathsea?=	teTeX-bin
BUILDLINK_DEPENDS.kpathsea?=	teTeX-bin>=2.0.2
BUILDLINK_PKGSRCDIR.kpathsea?=	../../print/teTeX-bin
BUILDLINK_DEPMETHOD.kpathsea?=	build

EVAL_PREFIX+=		BUILDLINK_PREFIX.kpathsea=teTeX-bin
BUILDLINK_PREFIX.kpathsea_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kpathsea=	include/kpathsea/*
BUILDLINK_FILES.kpathsea+=	lib/libkpathsea.*

BUILDLINK_TARGETS+=	kpathsea-buildlink

kpathsea-buildlink: _BUILDLINK_USE

.endif	# KPATHSEA_BUILDLINK2_MK
