# $NetBSD: Makefile,v 1.13 2023/03/11 05:25:17 pin Exp $

DISTNAME=	gospt-0.0.46
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
