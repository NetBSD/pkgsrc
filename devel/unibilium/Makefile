# $NetBSD: Makefile,v 1.3 2022/07/25 11:12:24 wiz Exp $

DISTNAME=	unibilium-2.1.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=neovim/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/neovim/unibilium
COMMENT=	Basic terminfo library
LICENSE=	gnu-lgpl-v3

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake perl

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	unibilium.pc.in

.include "../../mk/bsd.pkg.mk"
