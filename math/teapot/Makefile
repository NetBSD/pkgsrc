# $NetBSD: Makefile,v 1.11 2024/08/25 06:19:02 wiz Exp $

DISTNAME=	teapot-2.3.0
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://www.syntax-k.de/projekte/teapot/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.syntax-k.de/projekte/teapot/
COMMENT=	Curses based spread sheet program
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_CONFIGURE_ARGS+=	-DENABLE_HELP=NO

CFLAGS.SunOS+=	-D__EXTENSIONS__
LDFLAGS.SunOS+=	-lnsl

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
