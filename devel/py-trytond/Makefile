# $NetBSD: Makefile,v 1.22 2021/12/22 22:33:30 mef Exp $
TRYTON_MODULE_NAME=	trytond
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=     devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Tryton server
LICENSE=	gnu-gpl-v3

DEPENDS+=	# TODO: lxml>=2.0
DEPENDS+=	# TODO: relatorio[fodt]>=0.7.0
DEPENDS+=	# TODO: Genshi>=0
DEPENDS+=	# TODO: python-dateutil>=0
DEPENDS+=	# TODO: polib>=0
DEPENDS+=	# TODO: python-sql>=0.5
DEPENDS+=	# TODO: werkzeug>=0
DEPENDS+=	# TODO: wrapt>=0
DEPENDS+=	# TODO: passlib>=1.7.0
TEST_DEPENDS+=	# TODO: pillow>=0

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
