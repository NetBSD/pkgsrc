# $NetBSD: Makefile,v 1.19 2004/01/20 12:12:49 agc Exp $

DISTNAME=	db-2.7.7
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/src/misc/ \
		ftp://ftp.gwdg.de/pub/languages/perl/CPAN/src/misc/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.sleepycat.com/
COMMENT=	Sleepycat Software's Berkeley DB version 2

NO_PKGTOOLS_REQD_CHECK=	# defined (needed for pkgtools/pkg_install)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/build_unix
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS+=	--enable-compat185

USE_GNU_TOOLS+=		awk

INSTALLATION_DIRS=	bin include/db2 lib share/doc/html

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/html/db

.include "../../mk/bsd.pkg.mk"
