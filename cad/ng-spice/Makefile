# $NetBSD: Makefile,v 1.2 2001/02/16 13:46:26 wiz Exp $
#

DISTNAME=	ng-spice-rework-13
PKGNAME=	ng-spice-13
CATEGORIES=	cad
MASTER_SITES=	ftp://ieee.ing.uniroma1.it/pub/ng-spice/distribution/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://ieee.ing.uniroma1.it/ngspice/
COMMENT=	Next generation circuit simulation program

.if !exists(/usr/include/getopt.h)
DEPENDS+=       libgetopt-*:../../devel/libgetopt
LDFLAGS+=       -Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -lgetopt
CPPFLAGS+=	-I${LOCALBASE}/include
.endif

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_CURSES=             YES
REPLACE_NCURSES=        configure configure.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
LDFLAGS+=       -Wl,-R${X11BASE}/lib -L${X11BASE}/lib
CONFIGURE_ENV+=		LDFLAGS+="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"

CONFLICTS+=		spice-*

.include "../../mk/bsd.pkg.mk"
