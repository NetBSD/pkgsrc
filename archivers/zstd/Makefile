# $NetBSD: Makefile,v 1.3 2016/12/04 19:04:24 wiz Exp $

DISTNAME=	zstd-1.1.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=facebook/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zstd.net/
COMMENT=	Fast real-time compression algorithm
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pkg-config
MAKE_FLAGS=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

PKGCONFIG_OVERRIDE+=	lib/libzstd.pc.in

.include "../../mk/bsd.pkg.mk"
