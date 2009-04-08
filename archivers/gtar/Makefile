# $NetBSD: Makefile,v 1.36 2009/04/08 22:47:07 joerg Exp $

DISTNAME=	gtar-1.20
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The "meta-package" for the GNU tape archiver (tar)

META_PACKAGE=	# empty

DEPENDS+=	gtar-base-1.20{,nb*}:../../archivers/gtar-base
DEPENDS+=	gtar-info-1.20{,nb*}:../../archivers/gtar-info

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
