# $NetBSD: Makefile,v 1.37 2009/07/17 04:47:27 rillig Exp $

DISTNAME=	gtar-1.20
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The "meta-package" for the GNU tape archiver (tar)

META_PACKAGE=	yes

DEPENDS+=	gtar-base-1.20{,nb*}:../../archivers/gtar-base
DEPENDS+=	gtar-info-1.20{,nb*}:../../archivers/gtar-info

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
