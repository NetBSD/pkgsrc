# $NetBSD: Makefile,v 1.5 1999/12/06 14:38:41 bouyer Exp $

DISTNAME=	db-2.7.7
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/2.7.7/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/src/misc/ \
		ftp://ftp.gwdg.de/pub/languages/perl/CPAN/src/misc/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.sleepycat.com/

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure

WRKSRC=		${WRKDIR}/${PKGNAME}/build_unix

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/db

.include "../../mk/bsd.pkg.mk"
.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=		--enable-compat185
.endif
