# $NetBSD: Makefile,v 1.23 2012/01/29 08:59:46 obache Exp $
#

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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		#none

NO_BUILD=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	27 26 25

PYATSPIDIR=		${PREFIX}/${PYSITELIB}/pyatspi
INSTALLATION_DIRS=	${PYATSPIDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/pyatspi/*.py ${DESTDIR}${PYATSPIDIR}
	${PY_COMPILE_ALL} ${DESTDIR}${PYATSPIDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
