# $NetBSD: Makefile,v 1.8 1998/08/15 00:12:10 tv Exp $
#

DISTNAME=       tar-1.12
PKGNAME=	gtar-1.12
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

USE_GTEXINFO=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-prefix=g --with-catgets

post-patch:
	@${ECHO} '' >>${WRKSRC}/po/fr.po

post-install:
	${INSTALL_DATA} ${FILESDIR}/gtar.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
