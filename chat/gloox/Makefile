# $NetBSD: Makefile,v 1.6 2012/10/03 00:02:36 asau Exp $

DISTNAME=		gloox-1.0
PKGREVISION=		2
CATEGORIES=		chat
MASTER_SITES=		http://camaya.net/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		schnoebe@cirr.com
HOMEPAGE=		http://camaya.net/gloox/
COMMENT=		Jabber/XMPP client library
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

USE_LANGUAGES+=		c++ c
USE_TOOLS+=		autoconf automake pkg-config
USE_LIBTOOL=		yes

LIBS.SunOS+=		-lnsl

.include "options.mk"

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
