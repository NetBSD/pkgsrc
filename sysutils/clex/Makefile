# $NetBSD: Makefile,v 1.15 2026/06/24 11:53:10 drixter Exp $

DISTNAME=		clex-4.7
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=xitop/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		https://github.com/xitop/clex
COMMENT=		File manager with a full-screen user interface
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		autoconf automake autoreconf
USE_CC_FEATURES+=	c99
GNU_CONFIGURE=		yes

CFLAGS.SunOS+=		-D__EXTENSIONS__

pre-configure:
	cd ${WRKSRC} && autoreconf -fi


.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
