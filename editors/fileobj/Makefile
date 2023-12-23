# $NetBSD: Makefile,v 1.21 2023/12/23 11:52:31 tkusumi Exp $

DISTNAME=	fileobj-0.8.1
CATEGORIES=	editors python
MASTER_SITES=	${MASTER_SITE_GITHUB:=kusumi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tkusumi@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/fileobj/
COMMENT=	Curses based hex editor with vi interface
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} fileobj fileobj-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
