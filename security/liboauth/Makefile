# $NetBSD: Makefile,v 1.26 2020/03/08 16:48:07 wiz Exp $

DISTNAME=	liboauth-1.0.3
PKGREVISION=	16
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=liboauth/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://liboauth.sourceforge.net/
COMMENT=	Embeddable oauth 1.0 implementation
LICENSE=	mit AND gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	oauth.pc.in

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
