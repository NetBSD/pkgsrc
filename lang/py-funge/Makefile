# $NetBSD: Makefile,v 1.9 2009/07/08 13:55:59 joerg Exp $

DISTNAME=	pyfunge-0.2-beta1
PKGNAME=	${PYPKGPREFIX}-funge-0.2beta1
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	http://kldp.net/download.php/1270/

MAINTAINER=	fox9@netb.co.kr
HOMEPAGE=	http://pyfunge.kldp.net/
COMMENT=	Extensible Funge-98 interpreter written in Python

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

NO_BUILD=	yes
NO_CONFIGURE=	yes

PYTHON_VERSIONS_ACCEPTED?=	23

WRKSRC?=	${WRKDIR}/PyFunge
PLIST_SUBST+=	PYSITELIB=${PYSITELIB:Q}

INSTALLATION_DIRS=	${PYSITELIB}/PyFunge share/doc/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/README.ko ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	cd ${WRKSRC} && pax -rwppm '-s|.*/README.ko||' \
		. ${DESTDIR}${PREFIX}/${PYSITELIB}/PyFunge
	${PY_COMPILE_ALL} ${DESTDIR}${PREFIX}/${PYSITELIB}/PyFunge
	${PY_COMPILE_O_ALL} ${DESTDIR}${PREFIX}/${PYSITELIB}/PyFunge

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
