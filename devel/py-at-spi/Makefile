# $NetBSD: Makefile,v 1.2 2007/12/22 00:17:35 joerg Exp $
#

DISTNAME=		at-spi-1.20.1
PKGNAME=		${PYPKGPREFIX}-at-spi-1.20.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/at-spi/1.20/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Assistive Technology Service Provider Interface

NO_BUILD=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	24

PYATSPIDIR=	${PREFIX}/${PYSITELIB}/pyatspi
do-install:
	${INSTALL_DATA_DIR} ${PYATSPIDIR}
	${INSTALL_DATA} ${WRKSRC}/pyatspi/*.py ${PYATSPIDIR}
	${PYTHONBIN} ${PREFIX}/${PYLIB}/compileall.py ${PYATSPIDIR}

.include "../../lang/python/extension.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
