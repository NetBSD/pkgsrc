# $NetBSD: Makefile,v 1.13 2006/02/05 23:08:58 joerg Exp $

DISTNAME=	ted-2.16.src
PKGNAME=	ted-en-us-2.16
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	US English spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../editors/ted

WRKSRC=		${WRKDIR}/Ted-2.16
USE_X11BASE=	YES
NO_BUILD=	YES

USE_TOOLS+=		gtar
INSTALLATION_DIRS=	share/Ted/ind

post-extract:
	@cd ${WRKSRC} ; ${GTAR} xf tedPackage/TedBindist.tar

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/US_English.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
