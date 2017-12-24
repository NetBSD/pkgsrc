# $NetBSD: Makefile,v 1.3 2017/12/24 10:14:43 wiz Exp $

DISTNAME=	qqwing-1.3.4
CATEGORIES=	games
MASTER_SITES=	https://qqwing.com/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://qqwing.com/
COMMENT=	Sudoku puzzle generator and solver
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	qqwing.pc.in

.include "../../mk/bsd.pkg.mk"
