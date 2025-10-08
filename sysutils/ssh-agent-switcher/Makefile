# $NetBSD: Makefile,v 1.16 2025/10/08 06:54:38 bsiegert Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		${GITHUB_PROJECT}-0.0.20231117
PKGREVISION=		15
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=jmmv/}
GITHUB_PROJECT=		ssh-agent-switcher
GITHUB_TAG=		3d5835ee0eeafdb2dd792f26d1decbed2c06dce8

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/jmmv/ssh-agent-switcher/
COMMENT=		SSH agent proxy for tmux
LICENSE=		modified-bsd

USE_LANGUAGES=		c

INSTALLATION_DIRS=	share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
