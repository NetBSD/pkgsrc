# $NetBSD: Makefile,v 1.42 2012/09/11 19:46:55 asau Exp $

DISTNAME=	gtar-1.26
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The "meta-package" for the GNU tape archiver (tar)
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.1

META_PACKAGE=	yes

DEPENDS+=	gtar-base-${PKGVERSION_NOREV}{,nb*}:../../archivers/gtar-base
DEPENDS+=	gtar-info-${PKGVERSION_NOREV}{,nb*}:../../archivers/gtar-info

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.pkg.mk"
