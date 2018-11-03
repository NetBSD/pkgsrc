# $NetBSD: Makefile,v 1.17 2018/11/03 12:47:16 leot Exp $

DISTNAME=	jq-1.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=stedolan/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/stedolan/jq/
COMMENT=	Command-line JSON processor
LICENSE=	mit

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	autoreconf autoconf automake bison flex gmake
GNU_CONFIGURE=	yes

TEST_TARGET=	check

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
