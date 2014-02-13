# $NetBSD: Makefile,v 1.4 2014/02/13 09:46:00 fhajny Exp $

DISTNAME=	rabbitmq-c-0.5.0
CATEGORIES=	net
MASTER_SITES=	https://github.com/alanxz/rabbitmq-c/releases/download/v${PKGVERSION_NOREV}/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/alanxz/rabbitmq-c
COMMENT=	C-language AMQP client library for use with AMQP servers
LICENSE=	mit

BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

USE_CMAKE=		yes
USE_LANGUAGES=		c c99
USE_TOOLS+=		pkg-config

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-build
SUBST_MESSAGE.man=	Fix man installation path
SUBST_FILES.man=	tools/CMakeLists.txt
SUBST_SED.man=		-e 's,share/man,${PKGMANDIR},'

CMAKE_ARGS+=		-DBUILD_TOOLS=ON
CMAKE_ARGS+=		-DBUILD_TOOLS_DOCS=ON
CMAKE_ARGS+=		-DENABLE_SSL_SUPPORT=ON

.include "../../devel/popt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
