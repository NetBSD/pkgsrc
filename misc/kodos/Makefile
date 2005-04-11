# $NetBSD: Makefile,v 1.4 2005/04/11 21:46:35 tv Exp $

DISTNAME=	kodos-2.4.2
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kodos/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://kodos.sourceforge.net/
COMMENT=	GUI for creating, testing and debugging Python REs

DEPENDS=	${PYPKGPREFIX}-qt3-modules>=3.11:../../x11/py-qt3-modules
DEPENDS+=	${PYPKGPREFIX}-qt3-sip>=4.0rc3:../../x11/py-qt3-sip

PYDISTUTILSPKG=	yes
USE_LANGUAGES=

SUBST_CLASSES+=		libpath
SUBST_STAGE.libpath=	pre-configure
SUBST_FILES.libpath=	setup.py
SUBST_SED.libpath=	-e "s|@LIBPATH@|${PREFIX}/share/kodos|g"

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
