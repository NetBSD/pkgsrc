# $NetBSD: Makefile,v 1.7 2008/05/26 02:13:21 joerg Exp $

DISTNAME=	pyfunge-0.2-beta1
PKGNAME=	${PYPKGPREFIX}-funge-0.2beta1
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	http://kldp.net/download.php/1270/

MAINTAINER=	fox9@netb.co.kr
HOMEPAGE=	http://pyfunge.kldp.net/
COMMENT=	Extensible Funge-98 interpreter written in Python

USE_TOOLS+=	pax

NO_BUILD=	yes
NO_CONFIGURE=	yes

PYTHON_VERSIONS_ACCEPTED?=	23

WRKSRC?=	${WRKDIR}/PyFunge
PLIST_SUBST+=	PYSITELIB=${PYSITELIB:Q}

PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.ko ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/${PYSITELIB}/PyFunge
	cd ${WRKSRC} && pax -rwppm '-s|.*/README.ko||' \
		. ${PREFIX}/${PYSITELIB}/PyFunge
	${PYTHONBIN} ${PYCOMPILEALL} ${PREFIX}/${PYSITELIB}/PyFunge
	${PYTHONBIN} -O ${PYCOMPILEALL} ${PREFIX}/${PYSITELIB}/PyFunge

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
