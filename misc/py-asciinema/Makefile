# $NetBSD: Makefile,v 1.1 2018/12/31 17:42:02 leot Exp $

DISTNAME=	asciinema-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asciinema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asciinema.org/
COMMENT=	Terminal session recorder
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=			# none
PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/asciinema ${DESTDIR}${PREFIX}/bin/asciinema${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
