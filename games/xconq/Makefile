# $NetBSD: Makefile,v 1.2 2000/08/23 23:14:26 tron Exp $

DISTNAME=		xconq-7.2.2
CATEGORIES=		games x11
MASTER_SITES=		ftp://sourceware.cygnus.com/pub/xconq/

MAINTAINER=		kleink@netbsd.org
HOMEPAGE=		http://sourceware.cygnus.com/xconq/

USE_X11BASE=		YES
USE_XPM=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-xpm

INFO_FILES=     	xcdesign.info xconq.info

post-build:
	cd ${WRKSRC}/doc && ${MAKE} info

post-install:
	cd ${WRKSRC}/doc && ${MAKE} install-info

.include "../../mk/bsd.pkg.mk"
