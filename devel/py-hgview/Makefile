# $NetBSD: Makefile,v 1.16 2017/01/03 13:23:02 jperkin Exp $

DISTNAME=	hgview-1.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	http://download.logilab.org/pub/hgview/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hgview.org/
COMMENT=	Visually navigate in a Mercurial repository history
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mercurial>=1.6:../../devel/py-mercurial
DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

REPLACE_PYTHON= *.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 1.8.0

USE_TOOLS+=	gmake

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/hgview ${DESTDIR}${PREFIX}/bin/hgview${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/qt4-qscintilla/buildlink3.mk"
.include "../../x11/py-qt4-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
