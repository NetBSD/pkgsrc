# $NetBSD: Makefile,v 1.1 2012/10/11 15:40:40 ryoon Exp $
#

DISTNAME=	json-c-0.10
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/downloads/json-c/json-c/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/json-c/json-c/wiki
COMMENT=	JSON library in C
LICENSE=	mit

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.
FETCH_USING=	curl

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	json.pc.in

.include "../../mk/bsd.pkg.mk"
