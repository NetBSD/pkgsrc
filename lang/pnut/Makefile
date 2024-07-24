# $NetBSD: Makefile,v 1.1 2024/07/24 11:48:58 schmonz Exp $

DISTNAME=		pnut-${GITHUB_TAG}
PKGNAME=		pnut-0.0.20240724
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GITHUB:=udem-dlteam/}
GITHUB_TAG=		1bc6a0d68de9e2284ddc2d9af889584cc6360616

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/udem-dlteam/pnut/
COMMENT=		C compiler written in POSIX shell and generating POSIX shell scripts
LICENSE=		2-clause-bsd

BUILD_TARGET=		build/pnut.sh

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
