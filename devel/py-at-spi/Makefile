# $NetBSD: Makefile,v 1.10 2009/07/10 22:22:39 abs Exp $
#

DISTNAME=		at-spi-1.26.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/at-spi/1.26/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Assistive Technology Service Provider Interface

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	26 25 24

PYATSPIDIR=		${PREFIX}/${PYSITELIB}/pyatspi
INSTALLATION_DIRS=	${PYATSPIDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/pyatspi/*.py ${DESTDIR}${PYATSPIDIR}
	${PY_COMPILE_ALL} ${DESTDIR}${PYATSPIDIR}

.include "../../lang/python/extension.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
