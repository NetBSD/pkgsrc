# $NetBSD: Makefile,v 1.1.1.1 2009/02/25 09:16:06 imil Exp $
#

DISTNAME=	pytemplate-1.5.1
PKGNAME=	py-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://www.bulot.org/downloads/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://bulot.org/wiki/doku.php?id=projects:python:pytemplate
COMMENT=	Pytemplate gives python developpers a starting framework

PKG_DESTDIR_SUPPORT=		user-destdir

USE_LANGUAGES=			# none

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	25 24
REPLACE_PYTHON=			${WRKSRC}/*.py

EGDIR=				${PREFIX}/share/examples/pytemplate

INSTALLATION_DIRS+=		${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/example.py ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/daemonexample.py ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/threadexample.py ${DESTDIR}${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
