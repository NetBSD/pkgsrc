# $NetBSD: Makefile,v 1.20 2020/06/11 20:55:10 leot Exp $

DISTNAME=	sqlmap-1.4.6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlmap/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://sqlmap.org/
COMMENT=	Automatic SQL injection and database takeover tool
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash:run perl:run

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

REPLACE_BASH+=	sqlmap/extra/shutils/autocompletion.sh
REPLACE_BASH+=	sqlmap/extra/shutils/blanks.sh
REPLACE_BASH+=	sqlmap/extra/shutils/drei.sh
REPLACE_BASH+=	sqlmap/extra/shutils/junk.sh
REPLACE_BASH+=	sqlmap/extra/shutils/modernize.sh
REPLACE_BASH+=	sqlmap/extra/shutils/postcommit-hook.sh
REPLACE_BASH+=	sqlmap/extra/shutils/precommit-hook.sh
REPLACE_BASH+=	sqlmap/extra/shutils/pycodestyle.sh
REPLACE_BASH+=	sqlmap/extra/shutils/pydiatra.sh
REPLACE_BASH+=	sqlmap/extra/shutils/pyflakes.sh
REPLACE_BASH+=	sqlmap/extra/shutils/pypi.sh
REPLACE_BASH+=	sqlmap/extra/shutils/strip.sh

REPLACE_PERL+=	sqlmap/extra/icmpsh/icmpsh-m.pl

REPLACE_PYTHON+=	sqlmap/extra/shutils/duplicates.py

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
