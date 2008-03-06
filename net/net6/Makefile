# $NetBSD: Makefile,v 1.3 2008/03/06 14:53:53 wiz Exp $
#

DISTNAME=	net6-1.3.5
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://releases.0x539.de/net6/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gobby.0x539.de/
COMMENT=	Networking library for C++

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	net6-1.3.pc.in

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
