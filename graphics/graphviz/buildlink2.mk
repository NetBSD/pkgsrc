# $NetBSD: buildlink2.mk,v 1.3 2003/03/04 20:04:10 seb Exp $
#
# This Makefile fragment is included by packages that use graphviz.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(GRAPHVIZ_BUILDLINK2_MK)
GRAPHVIZ_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			graphviz
BUILDLINK_DEPENDS.graphviz?=		graphviz>=1.9nb1
BUILDLINK_PKGSRCDIR.graphviz?=		../../graphics/graphviz

EVAL_PREFIX+=	BUILDLINK_PREFIX.graphviz=graphviz
BUILDLINK_PREFIX.graphviz_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.graphviz+=	include/graphviz/*
BUILDLINK_FILES.graphviz+=	lib/graphviz/*

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"

BUILDLINK_TARGETS+=	graphviz-buildlink

graphviz-buildlink: _BUILDLINK_USE

.endif	# GRAPHVIZ_BUILDLINK2_MK
