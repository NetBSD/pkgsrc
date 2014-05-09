# $NetBSD: Makefile,v 1.5 2014/05/09 07:36:58 wiz Exp $

DISTNAME=	RBTools-0.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.reviewboard.org/releases/RBTools/0.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.reviewboard.org/docs/manual/dev/users/tools/
COMMENT=	Tool to submit patches to a Review Board
LICENSE=	mit

USE_LANGUAGES=	# none

REPLACE_PYTHON=		ez_setup.py setup.py rbtools/postreview.py
REPLACE_PYTHON+=	contrib/internal/release.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
