# $NetBSD: Makefile,v 1.2 2005/10/31 17:34:20 tv Exp $
#

DISTNAME=	sysexits-1.0
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Substitute <sysexits.h> for OS's lacking it

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CHECKSUM=	YES
NO_BUILD=	YES

INSTALLATION_DIRS=	include

do-install:
	${INSTALL_DATA} ${FILESDIR}/sysexits.h ${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
