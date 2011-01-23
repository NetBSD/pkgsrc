# $NetBSD: Makefile,v 1.2 2011/01/23 22:27:36 tnn Exp $
#

VERSION=	0.21.0
DISTNAME=	logilab-astng-${VERSION}
EGG_NAME=	logilab_astng-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.logilab.org/pub/astng/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.logilab.org/project/logilab-astng
COMMENT=	Extend Python abstract syntax tree
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25 24

do-test:
	cd ${WRKSRC} && ${SH} test/fulltest.sh ${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../devel/py-logilab-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
