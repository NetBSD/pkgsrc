# $NetBSD: Makefile,v 1.8 2004/01/20 12:14:06 agc Exp $

DISTNAME=	Ted_es_ES
PKGNAME=	ted-es-2.14
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	Spanish spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../editors/ted

WRKSRC=		${WRKDIR}
USE_X11BASE=	YES

DIST_SUBDIR=	Ted-2.14
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/Spanish.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
