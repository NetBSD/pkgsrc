# $NetBSD: Makefile,v 1.1.1.1 1999/12/07 11:44:04 agc Exp $
#

DISTNAME=	packages.7
PKGNAME=	pkgmanpages-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/src/share/man/man7/

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.netbsd.org/

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${BSD_INSTALL_MAN} ${WRKSRC}/pub/NetBSD/NetBSD-current/src/share/man/man7/packages.7 ${PREFIX}/man/man7

.include "../../mk/bsd.pkg.mk"
