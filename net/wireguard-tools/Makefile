# $NetBSD: Makefile,v 1.1 2020/09/18 14:37:43 js Exp $

DISTNAME=	wireguard-tools-1.0.20200827
CATEGORIES=	net
MASTER_SITES=	https://git.zx2c4.com/wireguard-tools/snapshot/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://git.zx2c4.com/wireguard-tools/about/
COMMENT=	Userspace tooling for using and configuring WireGuard tunnels
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
MAKEFLAGS+=	WITH_BASHCOMPLETION=no
# wg-quick is a bunch of OS-specific shell scripts, currently lacking NetBSD
MAKEFLAGS+=	WITH_WGQUICK=no
MAKEFLAGS+=	WITH_SYSTEMDUNITS=no

WRKSRC=		${WRKDIR}/${DISTNAME}/src

.include "../../mk/bsd.pkg.mk"
