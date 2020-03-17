# $NetBSD: Makefile,v 1.29 2020/03/17 06:42:57 rillig Exp $

DISTNAME=	fribidi-1.0.9
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=fribidi/}
EXTRACT_SUFX=	.tar.xz
GITHUB_PROJECT=	fribidi
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fribidi/fribidi
COMMENT=	Free Implementation of the Unicode Bidirectional Algorithm
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

TEST_TARGET=	check

PKGCONFIG_OVERRIDE=	fribidi.pc.in

.include "../../mk/bsd.pkg.mk"
