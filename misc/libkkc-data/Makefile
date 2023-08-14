# $NetBSD: Makefile,v 1.8 2023/08/14 05:24:53 wiz Exp $

GITHUB_PROJECT=	libkkc
GITHUB_RELEASE=	v0.3.5
DISTNAME=	libkkc-data-0.2.7
PKGREVISION=	2
CATEGORIES=	misc japanese
MASTER_SITES=	${MASTER_SITE_GITHUB:=ueno/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ueno/libkkc
COMMENT=	Language model data for libkkc
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_ACCEPTED=	27 # py-marisa
TOOL_DEPENDS+=	${PYPKGPREFIX}-marisa-[0-9]*:../../textproc/py-marisa

GNU_CONFIGURE=	yes

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
