# $NetBSD: Makefile,v 1.5 2001/02/21 15:56:01 fvdl Exp $

DISTNAME=	db-3.2.9
PKGNAME=	db3-2.9
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/3.2.9/

MAINTAINER=	wrstuden@netbsd.org
HOMEPAGE=	http://www.sleepycat.com/
COMMENT=	Sleepycat Software's Berkeley DB version 3

#USE_LIBTOOL=		yes
#LTCONFIG_OVERRIDE=	${WRKDIR}/${DISTNAME}/dist/ltconfig
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure

CONFIGURE_ARGS+= --program-transform-name=s,db_,db3_,
CONFIGURE_ARGS+= --enable-cxx
#CONFIGURE_ARGS+=	--enable-shared

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/db3

.include "../../mk/bsd.pkg.mk"
