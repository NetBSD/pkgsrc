# $NetBSD: Makefile,v 1.10 2005/05/16 01:15:30 jlam Exp $

DISTNAME=	ted-2.16.src
PKGNAME=	ted-en-us-2.16
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

PKGSRC_USE_TOOLS+=	gtar

post-extract:
	@cd ${WRKSRC} ; ${GTAR} xf tedPackage/TedBindist.tar

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/US_English.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
