# $NetBSD: Makefile,v 1.7 2024/02/17 10:13:20 adam Exp $

OPENBLAS_VARIANT= openblas_openmp
.include "../../math/openblas/Makefile.common"
.if !empty(PKGSRC_COMPILER:M*clang*)
.include "../../parallel/openmp/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
