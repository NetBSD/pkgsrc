# $NetBSD: Makefile,v 1.9 2004/05/11 11:50:01 markd Exp $

DISTNAME=	Ted_nl_NL
PKGNAME=	ted-nl-2.16
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	Dutch spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../editors/ted

WRKSRC=		${WRKDIR}
USE_X11BASE=	YES

DIST_SUBDIR=	Ted-2.16
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/Dutch.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
