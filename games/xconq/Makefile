# $NetBSD: Makefile,v 1.1.1.1 1999/06/12 20:22:53 kleink Exp $
#

DISTNAME=		xconq-7.2.2
CATEGORIES=		games x11
MASTER_SITES=		ftp://sourceware.cygnus.com/pub/xconq/

MAINTAINER=		kleink@netbsd.org
HOMEPAGE=		http://sourceware.cygnus.com/xconq/

DEPENDS=		xpm-3.4k:../../graphics/xpm

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-xpm

INFO_FILES=     	xcdesign.info xconq.info

post-build:
	cd ${WRKSRC}/doc && ${MAKE} info

post-install:
	cd ${WRKSRC}/doc && ${MAKE} install-info

.include "../../mk/bsd.pkg.mk"
