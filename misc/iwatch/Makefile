# $NetBSD: Makefile,v 1.3 2021/05/14 13:23:22 nia Exp $

DISTNAME=	iwatch-1.0.4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=iij/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://github.com/iij/iwatch
COMMENT=	Watch the command output with interval timer
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_TOOLS=	gmake
USE_CURSES=	wide
MAKE_FILE=	GNUmakefile

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
