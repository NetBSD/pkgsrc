# $NetBSD: Makefile,v 1.2 2012/03/15 11:53:23 obache Exp $
#

DISTNAME=	RBTools-0.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.reviewboard.org/releases/RBTools/0.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.reviewboard.org/docs/manual/dev/users/tools/
COMMENT=	Tool to submit patches to a Review Board
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

REPLACE_PYTHON=		ez_setup.py setup.py rbtools/postreview.py
REPLACE_PYTHON+=	contrib/internal/release.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
