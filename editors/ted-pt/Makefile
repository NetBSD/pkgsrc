# $NetBSD: Makefile,v 1.7 2003/07/17 21:35:00 grant Exp $

DISTNAME=	Ted_pt_PT
PKGNAME=	ted-pt-2.14
WRKSRC=		${WRKDIR}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	Portuguese spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../editors/ted

USE_X11BASE=	YES

DIST_SUBDIR=	Ted-2.14
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/Portuguese.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
