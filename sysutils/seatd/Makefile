# $NetBSD: Makefile,v 1.1 2026/04/13 15:49:39 kikadf Exp $

DISTNAME=	seatd-0.9.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=kennylevinsen/}

MAINTAINER=	kikadf@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~kennylevinsen/seatd/
COMMENT=	Seat management daemon and library
LICENSE=	mit

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/libseat.pc

MESON_ARGS+=	-Dlibseat-logind=disabled
MESON_ARGS+=	-Dlibseat-builtin=enabled

SPECIAL_PERMS+=	bin/seatd-launch ${SETUID_ROOT_PERMS}

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/meson/build.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../mk/bsd.pkg.mk"
