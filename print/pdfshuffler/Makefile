# $NetBSD: Makefile,v 1.4 2016/07/09 13:04:02 wiz Exp $

DISTNAME=	pdfshuffler-0.6.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pdfshuffler/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/pdfshuffler/
COMMENT=	Simple PDF editor
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-Pdf-[0-9]*:../../print/py-Pdf
DEPENDS+=	${PYPKGPREFIX}-poppler-[0-9]*:../../print/py-poppler
DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

USE_LANGUAGES=	# none
REPLACE_PYTHON=	pdfshuffler/pdfshuffler.py pdfshuffler/pdfshuffler_iconview.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-gtk2

SUBST_CLASSES+=		manpath
SUBST_FILES.manpath+=	setup.py
SUBST_SED.manpath+=	-e "s,share/man,${PKGMANDIR},"
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	Fixing man page installation path.

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
