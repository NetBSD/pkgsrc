# $NetBSD: Makefile,v 1.20 2019/09/02 13:19:48 adam Exp $

.include "Makefile.common"

PKGREVISION=		6

CONFLICTS=		bittorrent-[0-9]*

DEPENDS+=	${PYPKGPREFIX}-cursespanel-[0-9]*:../../devel/py-cursespanel
DEPENDS+=	${PYPKGPREFIX}-crypto>=2.0:../../security/py-crypto

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.3.18

EGG_NAME=	BitTornado-T_${PKGVERSION_NOREV}._BitTornado_

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"

.include "../../mk/bsd.pkg.mk"
