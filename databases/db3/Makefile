# $NetBSD: Makefile,v 1.4 2001/02/16 14:17:22 wiz Exp $

DISTNAME=	db-3.0.55
PKGNAME=	db3-0.55
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/3.0.55/

MAINTAINER=	wrstuden@netbsd.org
HOMEPAGE=	http://www.sleepycat.com/
COMMENT=	Sleepycat Software's Berkeley DB version 3

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKDIR}/${DISTNAME}/dist/ltconfig
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure

CONFIGURE_ARGS+= --program-transform-name=s,db_,db3_,
#CONFIGURE_ARGS+=	--enable-shared

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/db3

.include "../../mk/bsd.pkg.mk"
