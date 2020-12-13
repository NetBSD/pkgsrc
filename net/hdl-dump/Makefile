# $NetBSD: Makefile,v 1.1 2020/12/13 15:47:18 nia Exp $

DISTNAME=	hdl-dump-20200727
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ps2homebrew/}
GITHUB_TAG=	92213b57d0c6a89d14d01d5a71bedb2c92ebd421

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ps2homebrew/hdl-dump
COMMENT=	Install games in HDLoader format to a PS2 hard drive
LICENSE=	gnu-gpl-v2

MAKE_FLAGS+=	RELEASE=yes
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hdl_dump ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
