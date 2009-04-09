# $NetBSD: Makefile,v 1.6 2009/04/09 00:48:08 joerg Exp $
#

DISTNAME=	sysexits-1.1
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Substitute <sysexits.h> for OS's lacking it

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	YES

INSTALLATION_DIRS=	include

do-install:
	${INSTALL_DATA} ${FILESDIR}/sysexits.h ${DESTDIR}${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
