# $NetBSD: Makefile,v 1.20 2023/07/15 10:52:52 bsiegert Exp $

DISTNAME=	gospt-0.0.50
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	-https://git.asdf.cafe/abs3nt/gospt/archive/v${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://git.asdf.cafe/abs3nt/gospt/
COMMENT=	Spotify TUI and CLI
LICENSE=	mit

# gospt is not really a Spotify client but, more of a client controller.
# You will need a client like 'librespot' running in the backgroud and to set
# that as device in gospt.

WRKSRC=	${WRKDIR}/${PKGBASE}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
