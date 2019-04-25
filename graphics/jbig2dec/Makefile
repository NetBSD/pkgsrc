# $NetBSD: Makefile,v 1.12 2019/04/25 07:32:58 maya Exp $

DISTNAME=	jbig2dec-0.16
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ArtifexSoftware/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ghostscript.com/jbig2dec.html
COMMENT=	JBIG2 decoder library
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	yes
USE_TOOLS+=	autoreconf autoconf automake
GNU_CONFIGURE=	yes

PYTHON_FOR_BUILD_ONLY=	test

TEST_TARGET=	check

REPLACE_PYTHON+=	test_jbig2dec.py

pre-configure:
	${RUN} cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
