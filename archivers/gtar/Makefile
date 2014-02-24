# $NetBSD: Makefile,v 1.43 2014/02/24 08:16:56 adam Exp $

DISTNAME=	gtar-1.27.1
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
