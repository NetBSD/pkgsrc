# $NetBSD: Makefile,v 1.10.2.1 2025/04/05 20:44:53 maya Exp $

DISTNAME=	sptui-0.1.2
PKGREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=szktkfm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
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
