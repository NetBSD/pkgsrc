# $NetBSD: Makefile,v 1.2 2012/05/21 06:56:04 dholland Exp $
#

DISTNAME=	trueskill-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	games devel
MASTER_SITES=	http://pypi.python.org/packages/source/t/trueskill/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.python.org/trueskill/
COMMENT=	Python module implementing the TrueSkill rating system
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	25

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
