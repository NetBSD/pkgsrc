# $NetBSD: Makefile,v 1.11 2002/05/25 20:06:01 wiz Exp $

DISTNAME=		irssi-0.8.4a
PKGNAME=		irssi-0.8.4.1
WRKSRC=			${WRKDIR}/irssi-0.8.4
CATEGORIES=		chat
MASTER_SITES=		http://real.irssi.org/files/
EXTRACT_SUFX=		.tar.bz2

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
