# $NetBSD: Makefile,v 1.10 2016/05/26 17:42:47 richard Exp $

DISTNAME=	RBTools-0.7.6
CATEGORIES=	devel
MASTER_SITES=	http://downloads.reviewboard.org/releases/RBTools/0.7/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.reviewboard.org/docs/manual/dev/users/tools/
COMMENT=	Tool to submit patches to a Review Board
LICENSE=	mit

USE_LANGUAGES=	# none

REPLACE_PYTHON=		ez_setup.py setup.py rbtools/postreview.py
REPLACE_PYTHON+=	contrib/internal/release.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.2

DEPENDS+=   ${PYPKGPREFIX}-six>=1.8.0:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
