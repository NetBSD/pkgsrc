# $NetBSD: Makefile,v 1.7 2009/07/03 15:59:49 drochner Exp $
#

DISTNAME=	net6-1.3.9
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://releases.0x539.de/net6/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gobby.0x539.de/
COMMENT=	Networking library for C++

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	net6-1.3.pc.in

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
.include "../../mk/bsd.pkg.mk"
