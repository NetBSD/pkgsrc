# $NetBSD: Makefile,v 1.3 2002/09/09 01:00:57 markd Exp $

R_PKGNAME=	KernSmooth
R_PKGVER=	2.22-7

MAINTAINER=	markd@netbsd.org
COMMENT=	Functions for kernel smoothing for Wand & Jones (1995)

USE_BUILDLINK2=	# defined

PLIST_SRC=	/dev/null

.include "../../math/blas/buildlink2.mk"

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
