# $NetBSD: Makefile,v 1.7 2022/01/31 09:48:35 wiz Exp $

DISTNAME=	confusable_homoglyphs-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/confusable_homoglyphs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vhf/confusable_homoglyphs
COMMENT=	Detect confusable usage of unicode homoglyphs
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES+=	click

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin \
		&& ${MV} confusable_homoglyphs confusable_homoglyphs-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
