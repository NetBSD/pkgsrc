# $NetBSD: Makefile,v 1.24.2.1 2026/07/14 00:35:41 maya Exp $

DISTNAME=	sptui-0.1.2
PKGREVISION=	22
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=szktkfm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/szktkfm/sptui/
COMMENT=	Spotify TUI player
LICENSE=	mit

# sptui is not really a Spotify client but, more of a client controller.
# It needs a client like 'librespot' or, 'spotifyd' running in the backgroud.

INSTALLATION_DIRS=	bin
USE_TOOLS+=		itstool gdbus-codegen perl

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/sptui \
		${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
