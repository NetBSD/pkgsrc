# $NetBSD: Makefile,v 1.4 2026/01/06 22:32:26 wiz Exp $

DISTNAME=	tack-1.11-20251210
PKGNAME=	${DISTNAME:S/-20/.20/}
CATEGORIES=	devel
MASTER_SITES=	https://invisible-island.net/archives/ncurses/current/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://invisible-island.net/ncurses/tack.html
COMMENT=	Verify or refine a terminfo description of a terminal
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME:S,-202.*,,}
GNU_CONFIGURE=	yes

# uses ncurses private symbols
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
