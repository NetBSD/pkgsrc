# $NetBSD: Makefile,v 1.1.1.1 2000/11/14 14:28:14 dmcmahill Exp $
#

DISTNAME=	ng-spice-rework-13
PKGNAME=	ng-spice-13
CATEGORIES=	cad
MASTER_SITES=	ftp://ieee.ing.uniroma1.it/pub/ng-spice/distribution/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://ieee.ing.uniroma1.it/ngspice/

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
