# $NetBSD: Makefile,v 1.1 2018/03/17 22:15:30 mef Exp $

DISTNAME=	gdsCAD-0.4.5
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=     cad python
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=hohlraum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pythonhosted.org/gdsCAD/
COMMENT=	Package for creating, reading, and manipulating GDSII layout files
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
#PYTHON_VERSIONS_INCOMPATIBLE= 35 36 34
# PYSETUPBUILDTARGET= install

.include "../../lang/python/egg.mk"

pre-configure:
	(cd ${WRKSRC} ;\
	${ECHO} '__version__ =' "'"${PKGVERSION_NOREV}"'" >  gdsCAD/_version.py \
	)

.include "../../mk/bsd.pkg.mk"
