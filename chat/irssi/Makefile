# $NetBSD: Makefile,v 1.9 2002/04/12 01:50:34 hubertf Exp $

DISTNAME=		irssi-0.8.4
PKGREVISION=	1
CATEGORIES=		chat
MASTER_SITES=		http://www.irssi.org/files/

MAINTAINER=		mutru@cc.hut.fi
HOMEPAGE=		http://www.irssi.org/
COMMENT=                Secure and modular IRC client with text mode user interface

# list it into IPv6-ready packages
BUILD_DEFS+=		USE_INET6

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-terminfo \
			--enable-ipv6

.if defined(IRSSI_USE_PERL) && ${IRSSI_USE_PERL} == "YES"
USE_PERL5=	# defined
# actually we don't need --with-perl here, irssi is compiled with it by default
# but who knows what may happen in future versions
CONFIGURE_ARGS+=	--with-perl
.else
CONFIGURE_ARGS+=	--with-perl=no
.endif

USE_BUILDLINK_ONLY=	yes
USE_CONFIG_WRAPPER=	yes

.include "../../devel/glib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
