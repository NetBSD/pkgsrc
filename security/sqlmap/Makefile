# $NetBSD: Makefile,v 1.3 2017/05/09 11:39:07 adam Exp $

DISTNAME=	sqlmap-1.1.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlmap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sqlmap.org/
COMMENT=	Automatic SQL injection and database takeover tool
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash:run perl:run

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

REPLACE_BASH+=	sqlmap/extra/shutils/blanks.sh
REPLACE_BASH+=	sqlmap/extra/shutils/pep8.sh
REPLACE_BASH+=	sqlmap/extra/shutils/precommit-hook.sh
REPLACE_BASH+=	sqlmap/extra/shutils/postcommit-hook.sh
REPLACE_BASH+=	sqlmap/extra/shutils/pyflakes.sh
REPLACE_BASH+=	sqlmap/extra/shutils/pypi.sh
REPLACE_BASH+=	sqlmap/extra/shutils/strip.sh

REPLACE_PERL+=	sqlmap/extra/icmpsh/icmpsh-m.pl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 1.1.3

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
