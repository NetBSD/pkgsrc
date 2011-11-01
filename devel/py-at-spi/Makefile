# $NetBSD: Makefile,v 1.22 2011/11/01 06:01:02 sbd Exp $
#

DISTNAME=		at-spi-1.30.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/at-spi/1.30/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Assistive Technology Service Provider Interface
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	27 26 25

PYATSPIDIR=		${PREFIX}/${PYSITELIB}/pyatspi
INSTALLATION_DIRS=	${PYATSPIDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/pyatspi/*.py ${DESTDIR}${PYATSPIDIR}
	${PY_COMPILE_ALL} ${DESTDIR}${PYATSPIDIR}

.include "../../lang/python/extension.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
