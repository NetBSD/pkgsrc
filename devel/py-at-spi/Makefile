# $NetBSD: Makefile,v 1.5 2008/06/12 02:14:28 joerg Exp $
#

DISTNAME=		at-spi-1.22.1
PKGNAME=		${PYPKGPREFIX}-at-spi-1.22.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/at-spi/1.22/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Assistive Technology Service Provider Interface

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	25 24

PYATSPIDIR=		${PREFIX}/${PYSITELIB}/pyatspi
INSTALLATION_DIRS=	${PYATSPIDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/pyatspi/*.py ${DESTDIR}${PYATSPIDIR}
	${PYTHONBIN} ${PREFIX}/${PYLIB}/compileall.py ${DESTDIR}${PYATSPIDIR}

.include "../../lang/python/extension.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
