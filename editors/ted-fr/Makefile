# $NetBSD: Makefile,v 1.18 2020/01/26 17:31:07 rillig Exp $

DISTNAME=	Ted_fr_FR
PKGNAME=	ted-fr-2.16
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nllgg.nl/Ted/
COMMENT=	French spelling dictionary for the Ted word processor

DEPENDS+=	ted>=2.6:../../editors/ted

WRKSRC=		${WRKDIR}

DIST_SUBDIR=	Ted-2.16
NO_BUILD=	YES

INSTALLATION_DIRS=	share/Ted/ind

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/French.ind \
		${DESTDIR}${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
