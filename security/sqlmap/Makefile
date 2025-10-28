# $NetBSD: Makefile,v 1.39 2025/10/28 09:38:26 adam Exp $

DISTNAME=	sqlmap-1.9.10
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlmap/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://sqlmap.org/
COMMENT=	Automatic SQL injection and database takeover tool
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash:run perl:run

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

REPLACE_BASH+=	sqlmap/extra/shutils/*.sh
REPLACE_PERL+=	sqlmap/extra/icmpsh/icmpsh-m.pl

REPLACE_PYTHON+=	sqlmap/extra/shutils/duplicates.py
REPLACE_PYTHON+=	sqlmap/plugins/dbms/clickhouse/*.py
REPLACE_PYTHON+=	sqlmap/thirdparty/identywaf/identYwaf.py

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
