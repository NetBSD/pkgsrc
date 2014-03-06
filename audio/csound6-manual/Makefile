# $NetBSD: Makefile,v 1.1 2014/03/06 10:16:53 mrg Exp $

DISTNAME=		manual_src
PKGNAME=		csound6-manual-${CSOUND_VERSION}
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=csound/csound6/Csound6.02/}

MAINTAINER=		mrg@eterna.com.au
HOMEPAGE=		http://www.csounds.com/
COMMENT=		Csound6 Reference Manual

BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
BUILD_DEPENDS+=		python27-[0-9]*:../../lang/python27

CSOUND_VERSION=		6.02
WRKSRC=			${WRKDIR}/manual6
DIST_SUBDIR=		${PKGNAME_NOREV}
USE_TOOLS+=		gmake
EXTRACT_USING=		bsdtar
BUILD_TARGET=		html-dist

DOCDIR=			share/doc/csound6
INSTALLATION_DIRS+=	${DOCDIR}
MAKE_ENV+=		XSL_BASE_PATH=${PREFIX}/share/xsl/docbook/

SUBST_CLASSES+=		python
SUBST_SED.python=	-e "s,^	python ,	${PREFIX}/bin/python2.7 ,"
SUBST_FILES.python=	Makefile
SUBST_STAGE.python=	pre-build
SUBST_MESSAGE.python=	Fixing path to python.

do-install:
	cd ${WRKSRC}/html && pax -rw * ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
