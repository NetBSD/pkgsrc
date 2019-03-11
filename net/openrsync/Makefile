# $NetBSD: Makefile,v 1.1 2019/03/11 16:27:03 kamil Exp $

GITHUB_PROJECT=	openrsync
GITHUB_TAG=	f18392f58d1f0bc72917e3ac3a46be74c194688d
DISTNAME=	openrsync-0.20190221
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=kristapsdz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kristapsdz/openrsync
COMMENT=	BSD-licensed implementation of rsync
LICENSE=	isc

WRKSRC=		${WRKDIR}/openrsync-${GITHUB_TAG}

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
