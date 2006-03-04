# $NetBSD: Makefile,v 1.4 2006/03/04 21:29:30 jlam Exp $
#

DISTNAME=	sysexits-1.1
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Substitute <sysexits.h> for OS's lacking it

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CHECKSUM=	YES
NO_BUILD=	YES

INSTALLATION_DIRS=	include

do-install:
	${INSTALL_DATA} ${FILESDIR}/sysexits.h ${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
