# $NetBSD: Makefile,v 1.29 2008/02/16 05:25:57 obache Exp $

DISTNAME=	db-2.7.7
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/

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
