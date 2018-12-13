# $NetBSD: Makefile,v 1.5 2018/12/13 11:22:46 adam Exp $

DISTNAME=	xandikos-0.0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xandikos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.jelmer.uk/code/xandikos/
COMMENT=	Lightweight CalDAV/CardDAV server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.19.1:../../devel/py-dulwich
DEPENDS+=	${PYPKGPREFIX}-icalendar-[0-9]*:../../time/py-icalendar
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} xandikos xandikos-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
