# $NetBSD: Makefile,v 1.24 2019/04/26 13:14:05 maya Exp $

DISTNAME=	pyCardDAV-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyCardDAV/carddav/}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://lostpackets.de/pycarddav/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pycarddav.lostpackets.de/
COMMENT=	Simple way of accessing a CardDAV resource
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # as of 0.7.0

REPLACE_PYTHON=		pycarddav/ui.py
REPLACE_PYTHON+=	pycarddav/controllers/__init__.py
REPLACE_PYTHON+=	pycarddav/controllers/query.py
REPLACE_PYTHON+=	pycarddav/controllers/sync.py
REPLACE_PYTHON+=	pycarddav/model.py
REPLACE_PYTHON+=	pycarddav/carddav.py
REPLACE_PYTHON+=	pycarddav/backend.py
REPLACE_PYTHON+=	pycarddav/__init__.py

INSTALLATION_DIRS= bin ${PKGMANDIR}/man1 share/doc/py-carddav share/examples/py-carddav

post-install:
	${INSTALL_DATA} ${WRKSRC}/README* ${DESTDIR}${PREFIX}/share/doc/py-carddav
	${INSTALL_DATA} ${WRKSRC}/pycard.conf.sample ${DESTDIR}${PREFIX}/share/examples/py-carddav
	${INSTALL_DATA} ${WRKSRC}/doc/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
