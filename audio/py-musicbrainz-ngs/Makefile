# $NetBSD: Makefile,v 1.6 2023/10/23 06:37:33 wiz Exp $

DISTNAME=	python-musicbrainzngs-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//:S/ngs/-ngs/}
PKGREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_GITHUB:=alastair/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alastair/python-musicbrainzngs
COMMENT=	Python bindings for Musicbrainz' NGS service
LICENSE=	2-clause-bsd

GITHUB_PROJECT=	python-musicbrainzngs
GITHUB_TAG=	v${PKGVERSION_NOREV}

EGG_NAME=	${DISTNAME:S/python-//}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
