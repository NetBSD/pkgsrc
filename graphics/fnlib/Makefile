# $NetBSD: Makefile,v 1.15.2.1 2002/06/30 06:24:07 jlam Exp $

DISTNAME=		fnlib-0.5
PKGREVISION=		1
CATEGORIES=		x11 graphics
MASTER_SITES=		ftp://ftp.enlightenment.org/pub/e/enlightenment/libs/

MAINTAINER=		root@garbled.net
COMMENT=		color font rendering library for X11R6

USE_BUILDLINK2=		# defined
USE_X11BASE=		# defined
GNU_CONFIGURE=		# defined

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fnlib
	${INSTALL_DATA} ${WRKSRC}/doc/fontinfo.README ${PREFIX}/share/doc/fnlib

.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
