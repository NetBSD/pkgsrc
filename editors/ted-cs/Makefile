# $NetBSD: Makefile,v 1.6 2003/06/02 01:20:06 jschauma Exp $

DISTNAME=	Ted_cs_CZ
PKGNAME=	ted-cs-2.14
WRKSRC=		${WRKDIR}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	Czech spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../editors/ted

USE_X11BASE=	YES

DIST_SUBDIR=	Ted-2.14
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/Czech.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
