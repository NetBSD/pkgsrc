# $NetBSD: Makefile,v 1.4 2001/06/20 01:49:10 jlam Exp $
#

DISTNAME=	ng-spice-rework-13
PKGNAME=	ng-spice-13
CATEGORIES=	cad
MASTER_SITES=	ftp://ieee.ing.uniroma1.it/pub/ng-spice/distribution/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://ieee.ing.uniroma1.it/ngspice/
COMMENT=	Next generation circuit simulation program

CONFLICTS+=		spice-*

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-debug

USE_X11=		YES
#USE_CURSES=		YES
USE_BUILDLINK_ONLY=	YES

.include "../../devel/libgetopt/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
