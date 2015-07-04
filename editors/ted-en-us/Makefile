# $NetBSD: Makefile,v 1.20 2015/07/04 16:18:29 joerg Exp $

DISTNAME=	ted-2.16.src
PKGNAME=	ted-en-us-2.16
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	US English spelling dictionary for the Ted word processor

DEPENDS+=	ted>=2.6:../../editors/ted

WRKSRC=		${WRKDIR}/Ted-2.16
NO_BUILD=	YES

USE_TOOLS+=		tar
INSTALLATION_DIRS=	share/Ted/ind

post-extract:
	@cd ${WRKSRC} ; ${TAR} xf tedPackage/TedBindist.tar

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/US_English.ind \
		${DESTDIR}${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
