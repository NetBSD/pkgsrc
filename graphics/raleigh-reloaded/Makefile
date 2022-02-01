# $NetBSD: Makefile,v 1.2 2022/02/01 19:03:23 tsutsui Exp $

DISTNAME=	raleigh-reloaded-1.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=vlastavesely/}
GITHUB_PROJECT=	${PKGBASE}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/vlastavesely/raleigh-reloaded
COMMENT=	GTK-3.20 theme aiming to revive the classic Raleigh theme
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		# none
USE_TOOLS+=		pax
NO_BUILD=		yes

THEMENAME=		Raleigh-Reloaded
INSTALLATION_DIRS+=	share/themes/${THEMENAME}

do-install:
	cd ${WRKSRC}/src && \
	    pax -rwpp -s '/.*\.orig//' . ${DESTDIR}${PREFIX}/share/themes/${THEMENAME}/

.include "../../mk/bsd.pkg.mk"
