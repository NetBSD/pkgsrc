# $NetBSD: Makefile,v 1.2 2001/05/19 17:18:42 wiz Exp $

DISTNAME=	Ted_en_GB
PKGNAME=	ted-en-gb-2.10
WRKSRC=		${WRKDIR}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	UK English spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../editors/ted

USE_X11BASE=	YES

DIST_SUBDIR=	Ted-2.10
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/UK_English.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
