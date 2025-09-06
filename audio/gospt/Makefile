# $NetBSD: Makefile,v 1.41 2025/09/06 13:16:53 bsiegert Exp $

DISTNAME=	gospt-0.0.52
PKGREVISION=	17
CATEGORIES=	audio
MASTER_SITES=	-https://git.asdf.cafe/abs3nt/gospt/archive/v${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.asdf.cafe/abs3nt/gospt/
COMMENT=	Spotify TUI and CLI
LICENSE=	mit

# gospt is not really a Spotify client but, more of a client controller.
# You will need a client like 'librespot' or, 'spotifyd' running in the
# backgroud and to set that as device in gospt.

WRKSRC=	${WRKDIR}/${PKGBASE}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
