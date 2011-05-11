# $NetBSD: Makefile,v 1.41 2011/05/11 07:49:58 adam Exp $

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
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
