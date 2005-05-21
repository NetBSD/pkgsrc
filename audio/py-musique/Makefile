# $NetBSD: Makefile,v 1.1 2005/05/21 23:20:24 augustss Exp $
#

DISTNAME=	pymusique-0.5
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://fuware.nanocrew.net/pymusique/

MAINTAINER=	augustss@NetBSD.org
HOMEPAGE=	http://fuware.nanocrew.net/pymusique/
COMMENT=	Interface to the iTunes Music Store

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-mcrypt-[0-9]*:../../security/py-mcrypt
DEPENDS+=	${PYPKGPREFIX}-libxml2-[0-9]*:../../textproc/py-libxml2
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PYDISTUTILSPKG= yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
