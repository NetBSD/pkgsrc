# $NetBSD: Makefile,v 1.9 2012/03/15 11:53:35 obache Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=		5

CONFLICTS=		bittorrent-[0-9]*

DEPENDS+=	${PYPKGPREFIX}-cursespanel-[0-9]*:../../devel/py-cursespanel
DEPENDS+=	${PYPKGPREFIX}-crypto>=2.0:../../security/py-crypto

EGG_NAME=	BitTornado-T_${PKGVERSION_NOREV}._BitTornado_

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"

.include "../../mk/bsd.pkg.mk"
