# $NetBSD: Makefile,v 1.27 2024/11/01 12:52:40 wiz Exp $
#

DISTNAME=	libggz-0.0.14.1
PKGREVISION=	22
CATEGORIES=	games
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/ggzgamingzone/ggz/0.0.14.1/

MAINTAINER=	mrohrer@users.sourceforge.net
HOMEPAGE=	http://www.ggzgamingzone.org/
COMMENT=	GGZ Gaming Zone libraries

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-debug-gdb
CONFIGURE_ARGS+=	--with-tls
CONFIGURE_ARGS+=	--with-gcrypt

.include "../../mk/pthread.buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
