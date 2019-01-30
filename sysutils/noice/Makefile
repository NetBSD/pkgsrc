# $NetBSD: Makefile,v 1.2 2019/01/30 11:46:26 leot Exp $

DISTNAME=	noice-0.7
CATEGORIES=	sysutils
MASTER_SITES=	https://dl.2f30.org/releases/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://git.2f30.org/noice/
COMMENT=	Small curses-based file browser
LICENSE=	2-clause-bsd

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
