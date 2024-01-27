# $NetBSD: Makefile,v 1.1 2024/01/27 19:27:16 wiz Exp $

DISTNAME=	tack
PKGNAME=	tack-1.09
CATEGORIES=	devel
MASTER_SITES=	https://invisible-island.net/datafiles/release/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://invisible-island.net/ncurses/tack.html
COMMENT=	Verify or refine a terminfo description of a terminal
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes

# uses ncurses private symbols
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
