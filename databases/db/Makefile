# $NetBSD: Makefile,v 1.16 2003/12/04 04:14:05 grant Exp $

DISTNAME=	db-2.7.7
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/src/misc/ \
		ftp://ftp.gwdg.de/pub/languages/perl/CPAN/src/misc/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.sleepycat.com/
COMMENT=	Sleepycat Software's Berkeley DB version 2

NO_PKGTOOLS_REQD_CHECK=	# defined (needed for pkgtools/pkg_install)

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS+=	--enable-compat185

USE_GNU_TOOLS=		awk

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/html/db

.include "../../mk/bsd.pkg.mk"
