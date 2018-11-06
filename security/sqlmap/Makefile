# $NetBSD: Makefile,v 1.10 2018/11/06 13:55:41 leot Exp $

DISTNAME=	sqlmap-1.2.11
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlmap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sqlmap.org/
COMMENT=	Automatic SQL injection and database takeover tool
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash:run perl:run

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

REPLACE_BASH+=	sqlmap/extra/shutils/blanks.sh
REPLACE_BASH+=	sqlmap/extra/shutils/postcommit-hook.sh
REPLACE_BASH+=	sqlmap/extra/shutils/precommit-hook.sh
REPLACE_BASH+=	sqlmap/extra/shutils/pycodestyle.sh
REPLACE_BASH+=	sqlmap/extra/shutils/pydiatra.sh
REPLACE_BASH+=	sqlmap/extra/shutils/pyflakes.sh
REPLACE_BASH+=	sqlmap/extra/shutils/pypi.sh
REPLACE_BASH+=	sqlmap/extra/shutils/strip.sh

REPLACE_PERL+=	sqlmap/extra/icmpsh/icmpsh-m.pl

REPLACE_PYTHON+=	sqlmap/extra/shutils/duplicates.py
REPLACE_PYTHON+=	sqlmap/extra/shutils/pylint.py
REPLACE_PYTHON+=	sqlmap/extra/shutils/regressiontest.py

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 1.2.11

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
