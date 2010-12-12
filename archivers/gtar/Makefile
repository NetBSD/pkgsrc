# $NetBSD: Makefile,v 1.40 2010/12/12 13:10:39 wiz Exp $

DISTNAME=	gtar-1.25
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The "meta-package" for the GNU tape archiver (tar)
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.1

META_PACKAGE=	yes

DEPENDS+=	gtar-base-1.25{,nb*}:../../archivers/gtar-base
DEPENDS+=	gtar-info-1.25{,nb*}:../../archivers/gtar-info

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
