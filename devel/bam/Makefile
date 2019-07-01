# $NetBSD: Makefile,v 1.3 2019/07/01 13:39:43 nia Exp $

DISTNAME=	bam-0.5.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=matricks/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fstd.lkml@gmail.com
HOMEPAGE=	https://matricks.github.io/bam/
COMMENT=	Fast and flexible LUA-driven build system
LICENSE=	zlib

USE_LANGUAGES=	c

INSTALLATION_DIRS=	bin

do-build:
	set -e; cd ${WRKSRC}; \
	CC=${CC:Q} ./make_unix.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bam ${DESTDIR}${PREFIX}/bin/bam

.include "../../mk/bsd.pkg.mk"
