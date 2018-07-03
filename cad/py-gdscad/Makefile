# $NetBSD: Makefile,v 1.4 2018/07/03 05:03:04 adam Exp $

DISTNAME=	gdsCAD-0.4.5
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=     cad python
MASTER_SITES=	${MASTER_SITE_GITHUB:=hohlraum/}
GITHUB_PROJECT=	gdsCAD

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pythonhosted.org/gdsCAD/
COMMENT=	Package for creating, reading, and manipulating GDSII layout files
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE= 34 35 36 37
# PYSETUPBUILDTARGET= install

.include "../../lang/python/egg.mk"

pre-configure:
	(cd ${WRKSRC} ;\
	${ECHO} '__version__ =' "'"${PKGVERSION_NOREV}"'" >  gdsCAD/_version.py \
	)

.include "../../mk/bsd.pkg.mk"
