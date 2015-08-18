# $NetBSD: Makefile,v 1.5 2015/08/18 07:31:12 wiz Exp $

DISTNAME=	teapot-2.3.0
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.syntax-k.de/projekte/teapot/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://www.syntax-k.de/projekte/teapot/
COMMENT=	Curses based spread sheet program
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARGS+=	-DENABLE_HELP=NO

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
