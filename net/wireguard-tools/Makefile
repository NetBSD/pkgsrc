# $NetBSD: Makefile,v 1.3 2022/06/07 10:02:06 adam Exp $

DISTNAME=	wireguard-tools-1.0.20210914
CATEGORIES=	net
MASTER_SITES=	https://git.zx2c4.com/wireguard-tools/snapshot/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://git.zx2c4.com/wireguard-tools/about/
COMMENT=	Userspace tooling for using and configuring WireGuard tunnels
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	WITH_BASHCOMPLETION=no
# wg-quick is a bunch of OS-specific shell scripts, currently lacking NetBSD
MAKE_FLAGS+=	WITH_WGQUICK=no
MAKE_FLAGS+=	WITH_SYSTEMDUNITS=no

WRKSRC=		${WRKDIR}/${DISTNAME}/src

.include "../../mk/bsd.pkg.mk"
