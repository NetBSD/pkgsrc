# $NetBSD: Makefile,v 1.3 2002/03/13 17:36:53 fredb Exp $

DISTNAME=	Ted_da_DK
PKGNAME=	ted-da-2.10
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	Danish spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../editors/ted

USE_X11BASE=	YES

NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/Danish.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
