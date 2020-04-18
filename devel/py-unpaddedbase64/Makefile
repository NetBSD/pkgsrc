# $NetBSD: Makefile,v 1.1 2020/04/18 12:46:27 js Exp $

DISTNAME=	unpaddedbase64-${VERSION}
VERSION=	1.1.0
PKGNAME=	${PYPKGPREFIX}-1.1.0
CATEGORIES=	devel python
GITHUB_PROJECT=	python-unpaddedbase64
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/
COMMENT=	Encode and decode Base64 without "=" padding
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
WRKSRC=		${WRKDIR}/python-${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
