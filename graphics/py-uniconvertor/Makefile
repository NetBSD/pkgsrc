# $NetBSD: Makefile,v 1.18 2022/01/10 21:59:16 wiz Exp $

DISTNAME=	uniconvertor-1.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	http://uniconvertor.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sk1project.net/
COMMENT=	Universal vector graphics translator
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sk1libs-[0-9]*:../../graphics/py-sk1libs

USE_LANGUAGES=			c
PYTHON_SELF_CONFLICT=		yes
PYTHON_VERSIONS_ACCEPTED=	27 # py-sk1libs
REPLACE_PYTHON+=		src/__init__.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
