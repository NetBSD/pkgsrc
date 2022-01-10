# $NetBSD: Makefile,v 1.15 2022/01/10 18:52:28 wiz Exp $

DISTNAME=	pytemplate-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://www.bulot.org/downloads/

MAINTAINER=	imil@gcu.info
#HOMEPAGE=	http://bulot.org/wiki/doku.php?id=projects:python:pytemplate
COMMENT=	Pytemplate gives python developpers a starting framework

USE_LANGUAGES=			# none

REPLACE_PYTHON=			*.py
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.5.1

EGDIR=				${PREFIX}/share/examples/${PYPKGPREFIX}-pytemplate

PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}
PRINT_PLIST_AWK+=	{ gsub(/${PYPKGPREFIX:S|/|\\/|g}/, "$${PYPKGPREFIX}") }

INSTALLATION_DIRS+=		${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/example.py ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/daemonexample.py ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/threadexample.py ${DESTDIR}${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
