# $NetBSD: Makefile,v 1.6 2012/10/06 11:54:45 asau Exp $
#

DISTNAME=	libggz-0.0.14.1
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/ggzgamingzone/ggz/0.0.14.1/

MAINTAINER=	mrohrer@users.sourceforge.net
HOMEPAGE=	http://www.ggzgamingzone.org/
COMMENT=	GGZ Gaming Zone libraries

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+= --enable-debug-gdb
CONFIGURE_ARGS+= --with-tls
CONFIGURE_ARGS+= --with-gcrypt

.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
