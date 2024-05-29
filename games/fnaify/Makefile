# $NetBSD: Makefile,v 1.16 2024/05/29 16:32:34 adam Exp $

GITHUB_PROJECT=	fnaify
GITHUB_RELEASE=	${PKGVERSION_NOREV}
DISTNAME=	fnaify-3.0
PKGREVISION=	14
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=rfht/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rfht/fnaify/
COMMENT=	Launcher for games using the FNA engine
LICENSE=	isc

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run

NO_BUILD=		yes
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 bin share/fnaify

REPLACE_BASH+=			fnaify

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=			pkgsrc-paths
SUBST_STAGE.pkgsrc-paths=	pre-configure
SUBST_FILES.pkgsrc-paths+=	fnaify
SUBST_SED.pkgsrc-paths=		-e 's,^depdir.*,depdir=${PREFIX}/lib:${X11BASE}/lib,'
SUBST_SED.pkgsrc-paths+=	-e 's,^fnadir.*,fnadir=${PREFIX}/share/FNA/,'
SUBST_SED.pkgsrc-paths+=	-e s,/usr/local/,${PREFIX},
.if ${OPSYS} == "NetBSD"
SUBST_SED.pkgsrc-paths+=	-e s,ld.so,ld.elf_so,
.endif

.include "../../devel/libstubborn/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/faudio/buildlink3.mk"
.include "../../multimedia/libtheoraplay/buildlink3.mk"
.include "../../games/fna/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
