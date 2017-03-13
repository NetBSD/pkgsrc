# $NetBSD: Makefile,v 1.4 2017/03/13 05:22:05 adam Exp $

DISTNAME=	python-musicbrainzngs-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//:S/ngs/-ngs/}
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_GITHUB:=alastair/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alastair/python-musicbrainzngs
COMMENT=	Python bindings for Musicbrainz' NGS service
LICENSE=	2-clause-bsd

GITHUB_PROJECT=	python-musicbrainzngs
GITHUB_TAG=	v${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

EGG_NAME=	${DISTNAME:S/python-//}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
