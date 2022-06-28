# $NetBSD: Makefile,v 1.78 2022/06/28 11:34:36 wiz Exp $

COMMENT=	Fast C routines to compute DFTs (single and double precision)
PKGREVISION=	1

SUPERSEDES=	fftwf-[0-9]*
CONFLICTS+=	fftwf-[0-9]*

# The standard precision is double. We always build at least
# single in addition.
FFTW_PRECISION=	double float

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
