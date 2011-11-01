# $NetBSD: Makefile,v 1.16 2011/11/01 06:02:08 sbd Exp $
#

DISTNAME=	mnemosyne-1.2.2
PKGREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mnemosyne-proj/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mnemosyne-proj.org/
COMMENT=	Sophisticated flash-card tool which optimizes your learning process
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

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
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
