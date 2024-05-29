# $NetBSD: Makefile,v 1.34 2024/05/29 16:31:29 adam Exp $

DISTNAME=		gloox-1.0.27
PKGREVISION=		4
CATEGORIES=		chat
MASTER_SITES=		https://camaya.net/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://camaya.net/gloox/
COMMENT=		Jabber/XMPP client library
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes

USE_LANGUAGES+=		c++ c
USE_TOOLS+=		autoconf automake pkg-config
USE_LIBTOOL=		yes

LIBS.SunOS+=		-lnsl

# -pedantic in gcc 4.5.3 (NetBSD 6) is less pedantic than
# in gcc 4.1.3 (NetBSD 5.*) aka, -pedantic causes build
# failures when including gnutls on older versions of gcc.
BUILDLINK_TRANSFORM+=	rm:-pedantic

.include "options.mk"

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
