# $NetBSD: Makefile,v 1.7 2012/10/31 11:19:49 asau Exp $
#

DISTNAME=	sysexits-1.1
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Substitute <sysexits.h> for OS's lacking it

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=	YES

INSTALLATION_DIRS=	include

do-install:
	${INSTALL_DATA} ${FILESDIR}/sysexits.h ${DESTDIR}${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
