# $NetBSD: Makefile,v 1.5 2022/01/10 20:39:43 wiz Exp $

DISTNAME=	python-musicbrainzngs-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//:S/ngs/-ngs/}
PKGREVISION=	1
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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
