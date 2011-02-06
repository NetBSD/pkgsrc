# $NetBSD: Makefile,v 1.1.1.1 2011/02/06 19:46:48 schnoebe Exp $

DISTNAME=		gloox-1.0
CATEGORIES=		chat
MASTER_SITES=		http://camaya.net/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		schnoebe@cirr.com
HOMEPAGE=		http://camaya.net/gloox/
COMMENT=		Jabber/XMPP client library
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

USE_LANGUAGES+=		c++ c
USE_TOOLS+=		autoconf automake
USE_LIBTOOL=		yes

.include "options.mk"

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
