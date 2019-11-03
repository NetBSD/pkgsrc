# $NetBSD: Makefile,v 1.9 2019/11/03 10:18:28 rillig Exp $

DISTNAME=	hglist-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://alastairs-place.net/projects/hglist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://alastairs-place.net/projects/hglist/
COMMENT=	Mercurial ls command
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
