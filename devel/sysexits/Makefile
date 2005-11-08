# $NetBSD: Makefile,v 1.3 2005/11/08 13:34:39 tv Exp $
#

DISTNAME=	sysexits-1.1
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
