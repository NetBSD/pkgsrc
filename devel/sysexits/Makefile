# $NetBSD: Makefile,v 1.8 2014/10/09 14:06:31 wiz Exp $
#

DISTNAME=	sysexits-1.1
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Substitute <sysexits.h> for OS's lacking it

NO_BUILD=	YES

INSTALLATION_DIRS=	include

do-install:
	${INSTALL_DATA} ${FILESDIR}/sysexits.h ${DESTDIR}${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
