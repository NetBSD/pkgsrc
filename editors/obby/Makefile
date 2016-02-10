# $NetBSD: Makefile,v 1.11 2016/02/10 08:09:37 mef Exp $
#

DISTNAME=	obby-0.4.8
CATEGORIES=	editors
MASTER_SITES=	http://releases.0x539.de/obby/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gobby.0x539.de/
COMMENT=	Library for distributed editing
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

CXXFLAGS+=		-std=c++11

PKGCONFIG_OVERRIDE+=	obby-0.4.pc.in

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../net/net6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
