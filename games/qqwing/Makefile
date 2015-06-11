# $NetBSD: Makefile,v 1.2 2015/06/11 08:47:29 prlw1 Exp $

DISTNAME=	qqwing-1.3.4
CATEGORIES=	games
MASTER_SITES=	http://qqwing.com/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://qqwing.com/
COMMENT=	Sudoku puzzle generator and solver
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	qqwing.pc.in

.include "../../mk/bsd.pkg.mk"
