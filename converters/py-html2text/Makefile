# $NetBSD: Makefile,v 1.1 2016/12/04 21:12:59 rodent Exp $

DISTNAME=	html2text-2016.9.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python textproc
MASTER_SITES=	https://files.pythonhosted.org/packages/source/h/html2text/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.ccom/Alir3z4/html2text
COMMENT=	Python script that converts a page of HTML into clean ASCII text
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/html2text \
		${DESTDIR}${PREFIX}/bin/html2text${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
