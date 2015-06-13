# $NetBSD: Makefile,v 1.13 2015/06/13 20:40:30 tsutsui Exp $

.include "Makefile.common"

PKGNAME=	ja-FreeWnn-lib-1.11alpha23

COMMENT+=	(Japanese client library)

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--disable-client
CONFIGURE_ARGS+=	--disable-cWnn
CONFIGURE_ARGS+=	--disable-kWnn

INSTALL_TARGET=		install install.man

.include "../../mk/bsd.pkg.mk"
