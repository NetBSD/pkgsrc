# $NetBSD: Makefile,v 1.6 2022/07/25 11:04:45 wiz Exp $

GITHUB_PROJECT=	adaptagrams
GITHUB_TAG=	0503f7524f5b2aa96b356dfdd817f9f9869d2b20
# Date of the latest git commit
DISTNAME=	adaptagrams-0.20160901
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjwybrow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.adaptagrams.org/
COMMENT=	Tools for adaptive diagrams
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING+=	bsdtar

WRKSRC=		${WRKDIR}/adaptagrams-${GITHUB_TAG}/cola

USE_TOOLS+=	aclocal autoconf autoheader automake autoreconf pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes

TEST_TARGET=	check

pre-configure:
# ./autogen.sh runs ./configure && make && make check and sets questionable shebang
	${RUN} cd ${WRKSRC} && ${MKDIR} -p m4 && autoreconf -fiv

.include "../../graphics/cairomm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
