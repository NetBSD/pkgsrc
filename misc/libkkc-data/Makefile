# $NetBSD: Makefile,v 1.4 2019/04/25 07:33:07 maya Exp $

DISTNAME=	libkkc-data-0.2.7
PKGREVISION=	1
CATEGORIES=	misc japanese
#MASTER_SITES=	https://bitbucket.org/libkkc/libkkc-data/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ueno/libkkc
COMMENT=	Language model data for libkkc
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-marisa-[0-9]*:../../textproc/py-marisa

GNU_CONFIGURE=	yes

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
