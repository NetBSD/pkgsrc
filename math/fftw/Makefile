# $NetBSD: Makefile,v 1.80 2026/01/19 13:47:13 mef Exp $

COMMENT=	Fast C routines to compute DFTs (single and double precision)
PKGREVISION=	3

SUPERSEDES=	fftwf-[0-9]*
CONFLICTS+=	fftwf-[0-9]*

# The standard precision is double. We always build at least
# single in addition.
FFTW_PRECISION=	double float

.include "Makefile.common"

# referenced by FFTW3*Config.cmake
post-install:
	touch ${DESTDIR}${PREFIX}/lib/cmake/fftw3/FFTW3LibraryDepends.cmake

.include "../../mk/bsd.pkg.mk"
