# $NetBSD: Makefile,v 1.1 2015/09/12 18:51:07 wiz Exp $

# The upstream distfile would be
# http://github.com/downloads/matricks/bam/bam-0.4.0.tar.gz
# But url2pkg rejects it, and pkgsrc cannot fetch it either
# for reasons yet to be discovered.  Hence, the file is mirrored.
DISTNAME=	bam-0.4.0
CATEGORIES=	devel
MASTER_SITES=	http://penenen.de/

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
