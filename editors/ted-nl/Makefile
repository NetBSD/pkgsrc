# $NetBSD: Makefile,v 1.1.1.1 2001/05/14 14:42:19 wiz Exp $

DISTNAME=	Ted_NL
PKGNAME=	ted-nl-2.6
WRKSRC=		${WRKDIR}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	Dutch spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../editors/ted

USE_X11BASE=	YES

NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/Dutch.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
