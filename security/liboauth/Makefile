# $NetBSD: Makefile,v 1.8 2015/09/10 23:05:53 prlw1 Exp $

DISTNAME=	liboauth-1.0.3
CATEGORIES=	security
MASTER_SITES=	http://liboauth.sourceforge.net/pool/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://liboauth.sourceforge.net/
COMMENT=	Embeddable oauth 1.0 implementation
LICENSE=	mit AND gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	oauth.pc.in

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
