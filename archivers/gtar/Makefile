# $NetBSD: Makefile,v 1.6 1998/04/17 09:37:22 agc Exp $
#

DISTNAME=       tar-1.12
PKGNAME=	gtar-1.12
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

USE_GTEXINFO=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-prefix=g

MAN1=		gtar.1

post-install:
	${INSTALL_DATA} ${FILESDIR}/gtar.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
