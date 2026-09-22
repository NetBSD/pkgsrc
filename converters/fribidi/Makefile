# $NetBSD: Makefile,v 1.39 2026/09/22 10:51:08 ryoon Exp $

DISTNAME=	fribidi-1.0.17
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=fribidi/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fribidi/fribidi
COMMENT=	Free Implementation of the Unicode Bidirectional Algorithm
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

TEST_TARGET=	check

PKGCONFIG_OVERRIDE=	fribidi.pc.in

.include "../../mk/bsd.pkg.mk"
