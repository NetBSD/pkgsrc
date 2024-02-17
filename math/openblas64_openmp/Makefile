# $NetBSD: Makefile,v 1.4 2024/02/17 10:13:19 adam Exp $

OPENBLAS_VARIANT= openblas64_openmp
.include "../../math/openblas/Makefile.common"
.if !empty(PKGSRC_COMPILER:M*clang*)
.include "../../parallel/openmp/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
