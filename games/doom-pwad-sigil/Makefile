# $NetBSD: Makefile,v 1.4 2021/06/25 14:25:00 micha Exp $

DISTNAME=		sigil_v1_21
PKGNAME=		doom-pwad-sigil-1.21
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.fu-berlin.de/pc/games/idgames/levels/doom/Ports/s-u/
MASTER_SITES+=		ftp://mirrors.syringanetworks.net/idgames/levels/doom/Ports/s-u/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.romerogames.ie/si6il/
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

TOOL_DEPENDS+=		dos2unix-[0-9]*:../../converters/dos2unix
NO_BUILD=		yes

do-patch:
	dos2unix ${WRKDIR}/SIGIL_instructions.txt

pre-configure:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKSRC}

do-install:
	cd ${WRKDIR} &&	${INSTALL_DATA} SIGIL_v1_21.wad			\
		${DESTDIR}${PREFIX}/${DOOMWADDIR}/SIGIL.wad
	cd ${WRKDIR} && ${INSTALL_DATA} SIGIL_COMPAT_v1_21.wad		\
		${DESTDIR}${PREFIX}/${DOOMWADDIR}/SIGIL_COMPAT.wad
	cd ${WRKDIR} && ${INSTALL_DATA} sigil_v1_21.txt			\
		${DESTDIR}${PREFIX}/${DOOMWADDIR}/SIGIL.txt
	cd ${WRKDIR} && ${INSTALL_DATA} SIGIL_instructions.txt		\
		${DESTDIR}${PREFIX}/share/doc/doom-pwad-sigil/SIGIL_instructions.txt
	cd ${WRKSRC} &&	${INSTALL_DATA} INSTALL.pkgsrc			\
		${DESTDIR}${PREFIX}/share/doc/doom-pwad-sigil/INSTALL.pkgsrc

.include "../../mk/bsd.pkg.mk"
