# $NetBSD: Makefile,v 1.1.1.1 2001/09/16 16:14:09 hubertf Exp $

DISTNAME=		irssi-0.7.98.4
CATEGORIES=		chat
MASTER_SITES=		http://www.irssi.org/files/

MAINTAINER=		mutru@nallukka.net
HOMEPAGE=		http://www.irssi.org/
COMMENT=                Secure and modular IRC client with text mode user interface

DEPENDS+=		glib>=1.2:../../devel/glib
DEPENDS+=		ncurses>=5.0:../../devel/ncurses

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-perl=no

.include "../../mk/bsd.pkg.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
.endif
