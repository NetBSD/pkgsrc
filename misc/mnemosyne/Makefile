# $NetBSD: Makefile,v 1.1.1.1 2008/09/06 12:51:39 wiz Exp $
#

DISTNAME=	mnemosyne-1.1.1
CATEGORIES=	misc
MASTER_SITES=	http://downloads.sourceforge.net/mnemosyne-proj/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mnemosyne-proj.org/
COMMENT=	Sophisticated flash-card tool which optimizes your learning process

USE_DIRS+=	xdg-1.4
USE_LANGUAGES=	# none
# XXX: no py-qt package for python-2.5 available
PYTHON_VERSIONS_INCOMPATIBLE=	25

EGG_NAME=	${DISTNAME:S/^m/M/}

SUBST_CLASSES+=			installpath
SUBST_SED.installpath=		-e 's,/usr/share,${PREFIX}/share,'
SUBST_FILES.installpath=	setup.py
SUBST_MESSAGE.installpath=	Fixing installation path.
SUBST_STAGE.installpath=	pre-build

.include "../../devel/py-game/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
