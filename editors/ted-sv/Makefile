# $NetBSD: Makefile,v 1.5 2003/04/09 13:26:49 markd Exp $

DISTNAME=	Ted_sv_SE
PKGNAME=	ted-sv-2.14
WRKSRC=		${WRKDIR}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	Swedish spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../editors/ted

USE_X11BASE=	YES

DIST_SUBDIR=	Ted-2.14
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/Swedish.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
