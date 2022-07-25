# $NetBSD: Makefile,v 1.2 2022/07/25 11:12:26 wiz Exp $

DISTNAME=	openh264-2.1.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=cisco/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cisco/openh264
COMMENT=	H.264 encoder/decoder library from Cisco
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	openh264.pc.in

MAKE_FLAGS+=	ENABLEPIC=Yes
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	ARCH=${MACHINE_ARCH}
MAKE_FLAGS+=	HAVE_GMP_API=No

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
TOOL_DEPENDS+=	nasm>=2.07:../../devel/nasm
.endif

.include "../../mk/bsd.pkg.mk"
