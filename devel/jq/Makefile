# $NetBSD: Makefile,v 1.21 2024/07/11 19:59:07 riastradh Exp $

DISTNAME=	jq-1.7.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jqlang/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/jqlang/jq
COMMENT=	Command-line JSON processor
LICENSE=	mit

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex gmake
GNU_CONFIGURE=	yes

USE_CC_FEATURES=	c99
PKGCONFIG_OVERRIDE=	libjq.pc.in

TEST_TARGET=	check

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
