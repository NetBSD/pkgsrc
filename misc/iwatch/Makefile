# $NetBSD: Makefile,v 1.1 2016/05/06 09:02:36 nonaka Exp $

DISTNAME=	iwatch-1.0.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=iij/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://github.com/iij/iwatch
COMMENT=	Watch the command output with interval timer 
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_TOOLS=	gmake
MAKE_FILE=	GNUmakefile

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
