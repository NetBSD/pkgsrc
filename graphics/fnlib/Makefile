# $NetBSD: Makefile,v 1.17 2003/01/02 14:20:49 jmmv Exp $

DISTNAME=		fnlib-0.5
PKGREVISION=		2
CATEGORIES=		x11 graphics
MASTER_SITES=		ftp://ftp.enlightenment.org/pub/e/enlightenment/libs/

MAINTAINER=		root@garbled.net
COMMENT=		color font rendering library for X11R6

USE_BUILDLINK2=		# defined
USE_X11BASE=		# defined
GNU_CONFIGURE=		# defined

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"
EGDIR=			${PREFIX}/share/examples/fnlib
CONF_FILES=		${EGDIR}/fnrc ${PKG_SYSCONFDIR}/fnrc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fnlib
	${INSTALL_DATA} ${WRKSRC}/doc/fontinfo.README ${PREFIX}/share/doc/fnlib

.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
