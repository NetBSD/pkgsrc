# $NetBSD: Makefile,v 1.2 1999/04/19 21:19:00 tv Exp $

DISTNAME=	db-2.7.3
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.terra.net/pub/sleepycat/ \
		ftp://ftp.cs.tu-berlin.de/pub/misc/berkeley-db/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.sleepycat.com/

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure

WRKSRC=		${WRKDIR}/${PKGNAME}/build_unix

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/db

.include "../../mk/bsd.pkg.mk"
