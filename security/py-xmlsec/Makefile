# $NetBSD: Makefile,v 1.5 2013/02/06 23:23:44 jperkin Exp $
#

DISTNAME=	pyxmlsec-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
MASTER_SITES=	http://labs.libre-entreprise.org/frs/download.php/430/
PKGREVISION=	3
CATEGORIES=	security python

MAINTAINER=	pmcphee@givex.com
HOMEPAGE=	http://pyxmlsec.labs.libre-entreprise.org/
COMMENT=	Python bindings for XMLSec Library
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-libxml2-[0-9]*:../../textproc/py-libxml2

USE_TOOLS+=	pkg-config

PYDISTUTILSPKG=	yes

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/xmlsec1/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
