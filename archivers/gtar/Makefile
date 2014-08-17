# $NetBSD: Makefile,v 1.44 2014/08/17 16:28:18 wiz Exp $

.include "../../archivers/gtar/Makefile.common"

PKGNAME=	g${DISTNAME}
COMMENT=	The "meta-package" for the GNU tape archiver (tar)
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.1

META_PACKAGE=	yes

DEPENDS+=	gtar-base-${PKGVERSION_NOREV}{,nb*}:../../archivers/gtar-base
DEPENDS+=	gtar-info-${PKGVERSION_NOREV}{,nb*}:../../archivers/gtar-info

.include "../../mk/bsd.pkg.mk"
