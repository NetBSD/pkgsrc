# $NetBSD: Makefile,v 1.5 2001/11/29 01:12:26 hubertf Exp $

DISTNAME=		irssi-0.7.98.4
PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		http://www.irssi.org/files/

MAINTAINER=		mutru@nallukka.net
HOMEPAGE=		http://www.irssi.org/
COMMENT=                Secure and modular IRC client with text mode user interface

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-perl=no \
			--with-ncurses=${BUILDLINK_DIR}
USE_BUILDLINK_ONLY=	yes
USE_CONFIG_WRAPPER=	yes

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
