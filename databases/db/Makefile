# $NetBSD: Makefile,v 1.9.2.1 2002/06/30 06:24:06 jlam Exp $

DISTNAME=	db-2.7.7
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/2.7.7/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/src/misc/ \
		ftp://ftp.gwdg.de/pub/languages/perl/CPAN/src/misc/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.sleepycat.com/
COMMENT=	Sleepycat Software's Berkeley DB version 2

WRKSRC=		${WRKDIR}/${PKGNAME}/build_unix

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-compat185
.endif

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/html/db

.include "../../mk/bsd.pkg.mk"
