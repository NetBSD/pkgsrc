# $NetBSD: Makefile,v 1.4 2022/01/04 20:53:47 wiz Exp $

DISTNAME=	unpaddedbase64-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
GITHUB_PROJECT=	python-unpaddedbase64
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/python-unpaddedbase64
COMMENT=	Encode and decode Base64 without "=" padding
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
WRKSRC=		${WRKDIR}/python-${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
