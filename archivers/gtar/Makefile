# $NetBSD: Makefile,v 1.11 1999/04/14 21:39:01 tron Exp $
#

DISTNAME=       tar-1.12
PKGNAME=	gtar-1.12
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=tar/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html

USE_GTEXINFO=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-prefix=g --with-catgets

post-patch:
	@${ECHO} '' >>${WRKSRC}/po/fr.po

post-install:
	${INSTALL_DATA} ${FILESDIR}/gtar.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
