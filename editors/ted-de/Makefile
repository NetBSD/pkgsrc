# $NetBSD: Makefile,v 1.8 2004/01/20 12:14:05 agc Exp $

DISTNAME=	Ted_de_DE
PKGNAME=	ted-de-2.14
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	German spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../editors/ted

WRKSRC=		${WRKDIR}
USE_X11BASE=	YES

DIST_SUBDIR=	Ted-2.14
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/German.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
