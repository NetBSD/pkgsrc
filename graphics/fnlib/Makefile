# $NetBSD: Makefile,v 1.8 2000/06/01 11:23:27 rh Exp $

DISTNAME=		fnlib-0.5
CATEGORIES=		x11 graphics
MASTER_SITES=		ftp://ftp.enlightenment.org/pub/e/enlightenment/libs/

MAINTAINER=		root@garbled.net

DEPENDS+=		imlib-*:../../graphics/imlib

USE_X11BASE=		yes
USE_PKGLIBTOOL=		yes
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fnlib
	${INSTALL_DATA} ${WRKSRC}/doc/fontinfo.README ${PREFIX}/share/doc/fnlib

.include "../../mk/bsd.pkg.mk"
