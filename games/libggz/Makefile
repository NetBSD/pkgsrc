# $NetBSD: Makefile,v 1.3 2011/04/22 13:42:43 obache Exp $
#

DISTNAME=	libggz-0.0.14.1
PKGREVISION=	1
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
.include "../../mk/bsd.pkg.mk"
