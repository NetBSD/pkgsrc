# $NetBSD: Makefile,v 1.24 2006/06/18 07:04:16 rillig Exp $
#

DISTNAME=	tar-1.15.1
PKGNAME=	gtar-info-1.15.1
PKGREVISION=	1
SVR4_PKGNAME=	gtari
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=tar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	Info format documentation for the GNU tape archiver

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_BUILD=	yes
INFO_FILES=	yes

INSTALLATION_DIRS=	${PKGINFODIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/tar.info ${PREFIX}/${PKGINFODIR}

.include "../../mk/bsd.pkg.mk"
