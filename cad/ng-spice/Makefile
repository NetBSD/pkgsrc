# $NetBSD: Makefile,v 1.7 2001/09/27 23:17:46 jlam Exp $
#

DISTNAME=	ng-spice-rework-13
PKGNAME=	ng-spice-13
CATEGORIES=	cad
MASTER_SITES=	ftp://ieee.ing.uniroma1.it/pub/ng-spice/distribution/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://ieee.ing.uniroma1.it/ngspice/
COMMENT=	Next generation circuit simulation program

CONFLICTS+=		spice-[0-9]*

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-debug
LIBS+=			${LIBGETOPT}

USE_BUILDLINK_ONLY=	YES

.include "../../devel/libgetopt/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
