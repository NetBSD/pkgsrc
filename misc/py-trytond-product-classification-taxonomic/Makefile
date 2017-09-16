# $NetBSD: Makefile,v 1.2 2017/09/16 19:27:01 wiz Exp $
TRYTON_MODULE_NAME=	trytond_product_classification_taxonomic
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Tryton's product classification taxonomic module
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-product-classification>=${TRYTON_BASEVER}:../../misc/py-trytond-product-classification
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
