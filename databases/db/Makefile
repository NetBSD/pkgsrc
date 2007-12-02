# $NetBSD: Makefile,v 1.28 2007/12/02 13:04:07 wiz Exp $

DISTNAME=	db-2.7.7
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.gwdg.de/pub/languages/perl/CPAN/src/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oracle.com/database/berkeley-db.html
COMMENT=	Sleepycat Software's Berkeley DB version 2

NO_PKGTOOLS_REQD_CHECK=	yes	# (needed for pkgtools/pkg_install)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/build_unix
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS+=	--enable-compat185

INSTALLATION_DIRS=	bin include/db2 lib share/doc/html

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/html/db

.include "../../mk/bsd.pkg.mk"
