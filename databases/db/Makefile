# $NetBSD: Makefile,v 1.3 1999/10/07 17:41:48 tron Exp $

DISTNAME=	db-2.7.3
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.terra.net/pub/sleepycat/ \
		ftp://ftp.cs.tu-berlin.de/pub/misc/berkeley-db/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.sleepycat.com/

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure

WRKSRC=		${WRKDIR}/${PKGNAME}/build_unix

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/db

.include "../../mk/bsd.pkg.mk"
