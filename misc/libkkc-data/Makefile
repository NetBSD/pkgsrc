# $NetBSD: Makefile,v 1.2 2015/03/15 19:51:08 hiramatsu Exp $

DISTNAME=	libkkc-data-0.2.7
CATEGORIES=	misc japanese
MASTER_SITES=	https://bitbucket.org/libkkc/libkkc-data/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/libkkc/libkkc-data/
COMMENT=	Language model data for libkkc
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-marisa-[0-9]*:../../textproc/py-marisa

GNU_CONFIGURE=	yes

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
