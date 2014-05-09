# $NetBSD: Makefile,v 1.12 2014/05/09 07:37:13 wiz Exp $

.include "Makefile.common"

PKGREVISION=		5

CONFLICTS=		bittorrent-[0-9]*

DEPENDS+=	${PYPKGPREFIX}-cursespanel-[0-9]*:../../devel/py-cursespanel
DEPENDS+=	${PYPKGPREFIX}-crypto>=2.0:../../security/py-crypto

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.3.18

EGG_NAME=	BitTornado-T_${PKGVERSION_NOREV}._BitTornado_

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"

.include "../../mk/bsd.pkg.mk"
