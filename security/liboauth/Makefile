# $NetBSD: Makefile,v 1.1.1.1 2010/09/03 07:14:12 agc Exp $

DISTNAME=	liboauth-0.8.9
CATEGORIES=	security
MASTER_SITES=	http://liboauth.sourceforge.net/pool/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://liboauth.sourceforge.net/
COMMENT=	Embeddable oauth 1.0 implementation
LICENSE=	mit AND gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	oauth.pc.in

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
