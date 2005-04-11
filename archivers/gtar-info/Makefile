# $NetBSD: Makefile,v 1.19 2005/04/11 21:44:48 tv Exp $
#

DISTNAME=       tar-1.15.1
PKGNAME=	gtar-info-1.15.1
SVR4_PKGNAME=	gtari
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=tar/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	Info format documentation for the GNU tape archiver

INFO_FILES=	tar.info

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${INFO_DIR}
	for i in ${WRKSRC}/doc/tar.info* ; \
	do \
	    ${INSTALL_DATA} $${i} ${PREFIX}/${INFO_DIR} ; \
	done

.include "../../mk/bsd.pkg.mk"
