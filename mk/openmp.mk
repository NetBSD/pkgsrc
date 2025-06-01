# $NetBSD: openmp.mk,v 1.2 2025/06/01 20:25:33 wiz Exp $
#
# This Makefile fragment is meant to be included by packages that use
# OpenMP compiler extensions and may need an extra library package to
# support that. GCC ships its own libgomp, clang has it packaged separately.

.if !empty(PKGSRC_COMPILER:M*clang*)
.include "../../parallel/openmp/buildlink3.mk"
.endif
