# $NetBSD: Makefile,v 1.2 2008/11/29 21:17:20 snj Exp $

DISTNAME=	PySolFC-1.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysolfc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pysolfc.sourceforge.net/
COMMENT=	Over 1000 solitaire games

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCOMPATIBLE=	21

PYDISTUTILSPKG=	yes

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-patch
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		pysollib/settings.py
SUBST_SED.fix-paths=		-e s,@DATADIR@,${PREFIX}/share/PySolFC/,

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
