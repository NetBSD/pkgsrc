# $NetBSD: Makefile,v 1.65 2024/05/29 16:31:56 adam Exp $

DISTNAME=	ProjectCenter-0.6.2
PKGREVISION=	21
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=dev-apps/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/experience/ProjectCenter.html
COMMENT=	GNUstep Integrated Development Environment
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	destdir

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

SUBST_CLASSES+=		gmake
SUBST_STAGE.gmake=	pre-configure
SUBST_FILES.gmake+=	Framework/GNUmakefile.preamble
SUBST_FILES.gmake+=	Modules/Preferences/Build/PCBuildPrefs.h
SUBST_SED.gmake+=	-e 's|.(GMAKE)|${GMAKE:Q}|g'
SUBST_SED.gmake+=	-e 's|/usr/bin/make|${GMAKE:Q}|g'

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
