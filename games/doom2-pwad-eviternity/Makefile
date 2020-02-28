# $NetBSD: Makefile,v 1.1 2020/02/28 11:33:43 micha Exp $

VERS=			1.0
DISTNAME=		eviternity
PKGNAME=		doom2-pwad-eviternity-${VERS}
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.fu-berlin.de/pc/games/idgames/levels/doom2/Ports/megawads/
MASTER_SITES+=		ftp://mirrors.syringanetworks.net/idgames/levels/doom2/Ports/megawads/
EXTRACT_SUFX=		.zip
DIST_SUBDIR=		${PKGNAME_NOREV}

MAINTAINER=		micha@NetBSD.org
COMMENT=		Doom II mod
LICENSE=		cc-by-nc-nd-v4.0-license

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	${DOOMWADDIR} share/doc/doom2-pwad-eviternity

# Configure INSTALL.pkgsrc
SUBST_CLASSES+=		install
SUBST_STAGE.install=	do-configure
SUBST_MESSAGE.install=	Preparing INSTALL.pkgsrc file ...
SUBST_FILES.install=	INSTALL.pkgsrc
SUBST_SED.install=	-e 's,DOOMWADDIR,${PREFIX}/${DOOMWADDIR},'

TOOL_DEPENDS+=		dos2unix-[0-9]*:../../converters/dos2unix
WRKSRC=			${WRKDIR}
NO_BUILD=		yes

do-patch:
	cd "${WRKSRC}" && dos2unix Eviternity.txt

pre-configure:
	${CP} ${FILESDIR}/INSTALL.pkgsrc "${WRKSRC}"

do-install:
	cd "${WRKSRC}" && ${INSTALL_DATA} Eviternity.wad		\
		${DESTDIR}${PREFIX}/${DOOMWADDIR}/Eviternity.wad
	cd "${WRKSRC}" && ${INSTALL_DATA} Eviternity.txt		\
		${DESTDIR}${PREFIX}/${DOOMWADDIR}/Eviternity.txt
	cd "${WRKSRC}" && ${INSTALL_DATA} INSTALL.pkgsrc		\
		${DESTDIR}${PREFIX}/share/doc/doom2-pwad-eviternity/INSTALL.pkgsrc

.include "../../mk/bsd.pkg.mk"
