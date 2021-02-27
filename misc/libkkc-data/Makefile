# $NetBSD: Makefile,v 1.6 2021/02/27 19:18:13 ryoon Exp $

GITHUB_PROJECT=	libkkc
GITHUB_RELEASE=	v0.3.5
DISTNAME=	libkkc-data-0.2.7
PKGREVISION=	1
CATEGORIES=	misc japanese
MASTER_SITES=	${MASTER_SITE_GITHUB:=ueno/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ueno/libkkc
COMMENT=	Language model data for libkkc
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_ACCEPTED=	27 # py-marisa
BUILD_DEPENDS+=	${PYPKGPREFIX}-marisa-[0-9]*:../../textproc/py-marisa

GNU_CONFIGURE=	yes

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
