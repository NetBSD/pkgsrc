# $NetBSD: Makefile,v 1.5 2022/01/04 20:53:02 wiz Exp $

DISTNAME=	EditorConfig-0.12.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/EditorConfig/editorconfig-core/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=E/EditorConfig/}

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	https://editorconfig.org/
COMMENT=	Editorconfig python library
LICENSE=	python-software-foundation AND modified-bsd

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} editorconfig editorconfig-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
