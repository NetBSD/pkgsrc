# $NetBSD: Makefile,v 1.36 2024/06/09 13:59:57 wiz Exp $

DISTNAME=	fribidi-1.0.15
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=fribidi/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fribidi/fribidi
COMMENT=	Free Implementation of the Unicode Bidirectional Algorithm
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

TEST_TARGET=	check

PKGCONFIG_OVERRIDE=	fribidi.pc.in

.include "../../mk/bsd.pkg.mk"
