# $NetBSD: Makefile,v 1.28 2014/05/09 07:37:11 wiz Exp $

DISTNAME=	kodos-2.4.9
PKGREVISION=	6
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kodos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kodos.sourceforge.net/
COMMENT=	GUI for creating, testing and debugging Python REs

PYDISTUTILSPKG=	yes
USE_LANGUAGES=	# empty
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-qt3-modules

SUBST_CLASSES+=		libpath
SUBST_STAGE.libpath=	pre-configure
SUBST_FILES.libpath=	setup.py
SUBST_SED.libpath=	-e "s|@LIBPATH@|${PREFIX}/share/kodos|g"

.include "../../lang/python/extension.mk"
.include "../../x11/py-qt3-modules/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
