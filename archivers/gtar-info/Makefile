# $NetBSD: Makefile,v 1.16 2004/05/18 11:58:04 recht Exp $
#

DISTNAME=       tar-1.13.25
PKGNAME=	gtar-info-1.13.25
SVR4_PKGNAME=	gtari
CATEGORIES=	archivers
MASTER_SITES=	ftp://alpha.gnu.org/gnu/tar/ \
		ftp://ftp.sunsite.org.uk/Mirrors/alpha.gnu.org/gnu/tar/ \
		ftp://ftp.funet.fi/pub/mirrors/alpha.gnu.org/gnu/tar/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	Info format documentation for the GNU tape archiver

INFO_FILES=	tar.info

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${INFO_DIR}
	for i in ${WRKSRC}/doc/tar.info* ; \
	do \
	    ${INSTALL_DATA} $${i} ${PREFIX}/${INFO_DIR} ; \
	done

.include "../../mk/bsd.pkg.mk"
