# $NetBSD: Makefile,v 1.1.1.1 1999/12/16 02:36:05 hubertf Exp $

DISTNAME=	db-3.0.55
PKGNAME=	db3-0.55
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/3.0.55/

MAINTAINER=	wrstuden@netbsd.org
HOMEPAGE=	http://www.sleepycat.com/

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure

CONFIGURE_ARGS+= --program-transform-name=s,db_,db3_,

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/db3

.include "../../mk/bsd.pkg.mk"
