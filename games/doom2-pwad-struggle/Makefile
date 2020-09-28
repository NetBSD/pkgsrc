# $NetBSD: Makefile,v 1.3 2020/09/28 11:05:32 micha Exp $

DISTNAME=		strg
# Use release date from STRG.txt as package version
PKGNAME=		doom2-pwad-struggle-20180819
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.fu-berlin.de/pc/games/idgames/levels/doom2/Ports/megawads/
MASTER_SITES+=		ftp://mirrors.syringanetworks.net/idgames/levels/doom2/Ports/megawads/
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Doom II mod
LICENSE=		cc-by-nc-v4.0-license

.include "../../mk/bsd.prefs.mk"

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	${DOOMWADDIR} share/doc/doom2-pwad-struggle

# Configure INSTALL.pkgsrc (formerly displayed as MESSAGE)
SUBST_CLASSES+=		install
SUBST_STAGE.install=	do-configure
SUBST_MESSAGE.install=	Preparing INSTALL.pkgsrc file ...
SUBST_FILES.install=	INSTALL.pkgsrc
SUBST_SED.install=	-e 's,DOOMWADDIR,${PREFIX}/${DOOMWADDIR},'

NO_BUILD=		yes

pre-configure:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKSRC}

do-install:
	cd ${WRKDIR} &&							\
		${INSTALL_DATA} STRG.wad				\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/STRG.wad;	\
		${INSTALL_DATA} STRG_M28.wad				\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/STRG_M28.wad;	\
		${INSTALL_DATA} STRG.txt				\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/STRG.txt
	cd ${WRKSRC} &&							\
		${INSTALL_DATA} INSTALL.pkgsrc				\
			${DESTDIR}${PREFIX}/share/doc/doom2-pwad-struggle/INSTALL.pkgsrc

.include "../../mk/bsd.pkg.mk"
