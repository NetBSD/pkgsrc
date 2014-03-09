# $NetBSD: Makefile,v 1.1 2014/03/09 10:27:04 bsiegert Exp $

DISTNAME=	hgview-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://download.logilab.org/pub/hgview/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.logilab.org/pub/hgview/
COMMENT=	Visually navigate in a Mercurial repository history
LICENSE=	gnu-gpl-v2

DEPENDS+=	mercurial>=1.6:../../devel/mercurial

REPLACE_PYTHON= *.py

USE_TOOLS+=	gmake

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/qt4-qscintilla/buildlink3.mk"
.include "../../x11/py-qt4-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
