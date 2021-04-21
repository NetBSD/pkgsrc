# $NetBSD: Makefile,v 1.30 2021/04/21 13:24:15 adam Exp $

DISTNAME=	liboauth-1.0.3
PKGREVISION=	19
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=liboauth/}

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
