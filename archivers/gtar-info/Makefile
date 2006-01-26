# $NetBSD: Makefile,v 1.21 2006/01/26 18:19:03 reed Exp $
#

DISTNAME=       tar-1.15.1
PKGNAME=	gtar-info-1.15.1
SVR4_PKGNAME=	gtari
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=tar/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	Info format documentation for the GNU tape archiver

INFO_FILES=	tar.info

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	${INFO_DIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/tar.info ${PREFIX}/${INFO_DIR}

.include "../../mk/bsd.pkg.mk"
