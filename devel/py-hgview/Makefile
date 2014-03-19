# $NetBSD: Makefile,v 1.4 2014/03/19 21:05:14 wiz Exp $

DISTNAME=	hgview-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://download.logilab.org/pub/hgview/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.logilab.org/pub/hgview/
COMMENT=	Visually navigate in a Mercurial repository history
LICENSE=	gnu-gpl-v2

DEPENDS+=	mercurial>=1.6:../../devel/mercurial
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

REPLACE_PYTHON= *.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 1.8.0
PYTHON_VERSIONS_INCOMPATIBLE+=	26 # imports modules from mercurial, so needs to be the same version

USE_TOOLS+=	gmake

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/qt4-qscintilla/buildlink3.mk"
.include "../../x11/py-qt4-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
