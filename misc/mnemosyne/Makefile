# $NetBSD: Makefile,v 1.29 2014/05/09 07:37:11 wiz Exp $

DISTNAME=	mnemosyne-1.2.2
PKGREVISION=	16
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mnemosyne-proj/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mnemosyne-proj.org/
COMMENT=	Sophisticated flash-card tool which optimizes your learning process
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/^m/M/}
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-qt3-base, py-imaging

SUBST_CLASSES+=			installpath
SUBST_SED.installpath=		-e 's,/usr/share,${PREFIX}/share,'
SUBST_FILES.installpath=	setup.py
SUBST_MESSAGE.installpath=	Fixing installation path.
SUBST_STAGE.installpath=	pre-build

.include "../../devel/py-game/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/egg.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
