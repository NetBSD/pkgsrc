# $NetBSD: Makefile,v 1.20 2019/07/01 04:07:51 ryoon Exp $

DISTNAME=	liboauth-1.0.3
PKGREVISION=	11
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
