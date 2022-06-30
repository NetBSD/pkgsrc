# $NetBSD: Makefile,v 1.17 2022/06/30 11:18:20 nia Exp $

DISTNAME=	fileobj-0.7.108
PKGREVISION=	1
CATEGORIES=	editors python
MASTER_SITES=	${MASTER_SITE_GITHUB:=kusumi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tkusumi@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/fileobj/
COMMENT=	Curses based hex editor with vi interface
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} fileobj fileobj-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
