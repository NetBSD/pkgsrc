# $NetBSD: Makefile,v 1.8 2002/03/20 00:39:19 hubertf Exp $

DISTNAME=		irssi-0.8.4
CATEGORIES=		chat
MASTER_SITES=		http://www.irssi.org/files/

MAINTAINER=		mutru@cc.hut.fi
HOMEPAGE=		http://www.irssi.org/
COMMENT=                Secure and modular IRC client with text mode user interface

# list it into IPv6-ready packages
BUILD_DEFS+=		USE_INET6

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-perl=no \
			--with-terminfo \
			--enable-ipv6
USE_BUILDLINK_ONLY=	yes
USE_CONFIG_WRAPPER=	yes

.include "../../devel/glib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
