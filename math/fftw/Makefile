# $NetBSD: Makefile,v 1.77 2021/09/29 13:34:48 wiz Exp $

COMMENT=	Fast C routines to compute DFTs (single and double precision)

SUPERSEDES=	fftwf-[0-9]*
CONFLICTS+=	fftwf-[0-9]*

# The standard precision is double. We always build at least
# single in addition.
FFTW_PRECISION=	double float

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
