# $NetBSD: Makefile,v 1.2 2022/01/30 10:10:00 js Exp $

DISTNAME=	matrix-python-common-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-matrix-common-1.0.0
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_PROJECT=	matrix-python-common
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/matrix-python-common
COMMENT=	Common utilities for Synapse, Sydent and Sygnal
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
EGG_NAME=	matrix_common-${PKGVERSION_NOREV}

post-extract:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
