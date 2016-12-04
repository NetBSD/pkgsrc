# $NetBSD: Makefile,v 1.1 2016/12/04 21:13:06 rodent Exp $
TRYTON_MODULE_NAME=	trytond_product_classification_taxonomic
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Tryton's product classification taxonomic module
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-product-classification>=${TRYTON_BASEVER}:../../misc/py-trytond-product-classification
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
