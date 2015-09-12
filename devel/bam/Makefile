# $NetBSD: Makefile,v 1.2 2015/09/12 20:03:01 tnn Exp $

DISTNAME=	bam-0.4.0
CATEGORIES=	devel
MASTER_SITES=	https://cloud.github.com/downloads/matricks/bam/
MASTER_SITES+=	http://penenen.de/
#enable when updating next time
#EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	fstd.lkml@gmail.com
HOMEPAGE=	http://matricks.github.io/bam/
COMMENT=	Fast and flexible LUA-driven build system
LICENSE=	zlib

USE_LANGUAGES=	c

INSTALLATION_DIRS=	bin

do-build:
	set -e; cd ${WRKSRC}; \
	./make_unix.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bam ${DESTDIR}${PREFIX}/bin/bam

.include "../../mk/bsd.pkg.mk"
