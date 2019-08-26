# $NetBSD: Makefile,v 1.1 2019/08/26 16:48:56 micha Exp $

DISTNAME=		sigil_v1_1
PKGNAME=		doom2-pwad-sigil-1.1
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.fu-berlin.de/pc/games/idgames/levels/doom/Ports/s-u/
MASTER_SITES+=		ftp://mirrors.syringanetworks.net/idgames/levels/doom/Ports/s-u/
EXTRACT_SUFX=		.zip

MAINTAINER=		micha@NetBSD.org
COMMENT=		Doom mod
LICENSE=		doom-pwad-license

.include "../../mk/bsd.prefs.mk"

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	${DOOMWADDIR} share/doc/doom-pwad-sigil

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
		${INSTALL_DATA} SIGIL.wad				\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/SIGIL.wad;	\
		${INSTALL_DATA} SIGIL_COMPAT.wad			\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/SIGIL_COMPAT.wad; \
		${INSTALL_DATA} SIGIL.txt				\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/SIGIL.txt
	cd ${WRKSRC} &&							\
		${INSTALL_DATA} INSTALL.pkgsrc				\
			${DESTDIR}${PREFIX}/share/doc/doom-pwad-sigil/INSTALL.pkgsrc

.include "../../mk/bsd.pkg.mk"
