# $NetBSD: Makefile,v 1.7 1998/06/18 16:06:37 agc Exp $
#

DISTNAME=       tar-1.12
PKGNAME=	gtar-1.12
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

USE_GTEXINFO=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-prefix=g

post-install:
	${INSTALL_DATA} ${FILESDIR}/gtar.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
