# $NetBSD: Makefile,v 1.12 2002/11/18 20:22:53 jlam Exp $

DISTNAME=	db-2.7.7
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/src/misc/ \
		ftp://ftp.gwdg.de/pub/languages/perl/CPAN/src/misc/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.sleepycat.com/
COMMENT=	Sleepycat Software's Berkeley DB version 2

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS+=	--enable-compat185

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/html/db

.include "../../mk/bsd.pkg.mk"
