# $NetBSD: Makefile,v 1.3 2010/09/14 00:18:12 minskim Exp $

DISTNAME=	footmisc.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-5.5a
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE:S/-doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-footmisc

CONFLICTS+=	teTeX-texmf<=3.0nb17

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
