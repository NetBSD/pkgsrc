# $NetBSD: Makefile,v 1.4 2002/04/09 02:21:58 markd Exp $

DISTNAME=	ted-2.11.src
PKGNAME=	ted-en-us-2.11
WRKSRC=		${WRKDIR}/Ted-2.11
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	US English spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../editors/ted

USE_X11BASE=	YES
NO_BUILD=	YES

post-extract:
	@cd ${WRKSRC} ; ${GTAR} xf tedPackage/TedBindist.tar

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/US_English.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
