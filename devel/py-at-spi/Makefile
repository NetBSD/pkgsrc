# $NetBSD: Makefile,v 1.29 2016/07/09 13:03:39 wiz Exp $

DISTNAME=		at-spi-1.32.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/at-spi/1.32/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Assistive Technology Service Provider Interface
LICENSE=		gnu-lgpl-v2 # or later

DEPENDS+=		at-spi>=${PKGVERSION_NOREV}:../../devel/at-spi
DEPENDS+=		${PYPKGPREFIX}-gnome2-[0-9]*:../../x11/py-gnome2
DEPENDS+=		${PYPKGPREFIX}-ORBit-[0-9]*:../../net/py-ORBit

USE_LANGUAGES=		#none

NO_BUILD=	yes
PY_PATCHPLIST=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-ORBit, py-gnome2

PYATSPIDIR=		${PREFIX}/${PYSITELIB}/pyatspi
INSTALLATION_DIRS=	${PYATSPIDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/pyatspi/*.py ${DESTDIR}${PYATSPIDIR}
	${PY_COMPILE_ALL} ${DESTDIR}${PYATSPIDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
