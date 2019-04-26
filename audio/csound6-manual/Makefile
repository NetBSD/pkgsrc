# $NetBSD: Makefile,v 1.11 2019/04/26 13:13:41 maya Exp $

DISTNAME=		manual_src
PKGNAME=		csound6-manual-${CSOUND_VERSION}
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=csound/csound6/Csound6.02/}

MAINTAINER=		mrg@eterna.com.au
HOMEPAGE=		http://www.csounds.com/
COMMENT=		Csound6 Reference Manual
LICENSE=		gnu-fdl-v1.2

BUILD_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
BUILD_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

CSOUND_VERSION=		6.02
WRKSRC=			${WRKDIR}/manual6
DIST_SUBDIR=		${PKGNAME_NOREV}
USE_TOOLS+=		gmake pax
EXTRACT_USING=		bsdtar
BUILD_TARGET=		html-dist

DOCDIR=			share/doc/csound6
INSTALLATION_DIRS+=	${DOCDIR}
MAKE_ENV+=		XSL_BASE_PATH=${PREFIX}/share/xsl/docbook/

SUBST_CLASSES+=		python
SUBST_SED.python=	-e "s,^	python ,	${PYTHONBIN} ,"
SUBST_FILES.python=	Makefile
SUBST_STAGE.python=	pre-build
SUBST_MESSAGE.python=	Fixing path to python.

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # as of 6.02

do-install:
	cd ${WRKSRC}/html && pax -rw * ${DESTDIR}${PREFIX}/${DOCDIR}

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
