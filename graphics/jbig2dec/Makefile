# $NetBSD: Makefile,v 1.16 2020/09/13 11:12:45 leot Exp $

DISTNAME=	jbig2dec-0.19
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ArtifexSoftware/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jbig2dec.com/
COMMENT=	JBIG2 decoder library
LICENSE=	gnu-agpl-v3

USE_LIBTOOL=	yes
USE_TOOLS+=	autoreconf autoconf automake
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	jbig2dec.pc.in

PYTHON_FOR_BUILD_ONLY=	test

TEST_TARGET=	check

REPLACE_PYTHON+=	test_jbig2dec.py

pre-configure:
	${RUN} cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
