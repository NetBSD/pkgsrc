# $NetBSD: Makefile,v 1.43 2020/06/02 08:24:44 adam Exp $
#

DISTNAME=	burn-0.4.1
PKGREVISION=	20
CATEGORIES=	sysutils gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gsburn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gsburn.sourceforge.net/
COMMENT=	GNUstep based CD burning program
LICENSE=	gnu-gpl-v2

DEPENDS+=	cdparanoia>=3.0.9.8:../../audio/cdparanoia
DEPENDS+=	cdrtools>=1.10:../../sysutils/cdrtools
DEPENDS+=	cdrdao>=1.1.5:../../sysutils/cdrdao
DEPENDS+=	gworkspace-[0-9]*:../../sysutils/gworkspace

MAKE_FILE=	GNUmakefile
USE_TOOLS+=	gmake
USE_LANGUAGES=	objc
WRKSRC=		${WRKDIR}/Burn
MAKE_JOBS_SAFE=	no
MAKE_ENV+=	ADDITIONAL_CPPFLAGS=-D_POSIX_SOURCE
MAKE_ENV+=	ADDITIONAL_LDFLAGS=-lutil

FIX_GNUSTEP_INSTALLATION_DIR=		yes
SUBST_FILES.gnustep_installation_dir+=	Bundles/CDparanoia/GNUmakefile
SUBST_FILES.gnustep_installation_dir+=	Bundles/CDrecord/GNUmakefile
SUBST_FILES.gnustep_installation_dir+=	Bundles/MkIsoFs/GNUmakefile

.include "../../devel/gnustep-make/gnustep.mk"

do-configure:
	${LN} -s AudioCD ${BUILDLINK_DIR.cdplayer}/include/CDPlayer

.include "../../audio/cdplayer/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
