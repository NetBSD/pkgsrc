# $NetBSD: Makefile,v 1.1 2025/03/06 18:55:00 wiz Exp $

DISTNAME=	xdg-ninja-0.2.0.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=b3nj5m1n/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/b3nj5m1n/xdg-ninja/
COMMENT=	Check your home directory for unwanted files and directories
LICENSE=	mit

DEPENDS+=	glow-[0-9]*:../../textproc/glow
DEPENDS+=	jq-[0-9]*:../../devel/jq

USE_LANGUAGES=	# none
REPLACE_SH=	xdg-ninja.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man ${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
