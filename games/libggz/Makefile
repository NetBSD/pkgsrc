# $NetBSD: Makefile,v 1.4 2011/07/12 08:23:52 abs Exp $
#

DISTNAME=	libggz-0.0.14.1
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/ggzgamingzone/ggz/0.0.14.1/

MAINTAINER=	mrohrer@users.sourceforge.net
HOMEPAGE=	http://www.ggzgamingzone.org/
COMMENT=	GGZ Gaming Zone libraries

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+= --enable-debug-gdb
CONFIGURE_ARGS+= --with-tls
CONFIGURE_ARGS+= --with-gcrypt

.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
