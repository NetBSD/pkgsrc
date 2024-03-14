# $NetBSD: Makefile,v 1.79 2024/03/14 19:33:04 markd Exp $

COMMENT=	Fast C routines to compute DFTs (single and double precision)
PKGREVISION=	2

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
