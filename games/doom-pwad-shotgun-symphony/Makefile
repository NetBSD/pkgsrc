# $NetBSD: Makefile,v 1.1 2020/02/03 12:08:06 micha Exp $

DISTNAME=		sgnsym
PKGNAME=		doom-pwad-shotgun-symphony-1.0
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.fu-berlin.de/pc/games/idgames/levels/doom/Ports/s-u/
MASTER_SITES+=		ftp://mirrors.syringanetworks.net/idgames/levels/doom/Ports/s-u/
EXTRACT_SUFX=		.zip
DIST_SUBDIR=		${PKGNAME_NOREV}

MAINTAINER=		micha@NetBSD.org
COMMENT=		Doom mod
LICENSE=		doom-pwad-license

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	${DOOMWADDIR} share/doc/doom-pwad-shotgun-symphony

# Configure INSTALL.pkgsrc
SUBST_CLASSES+=		install
SUBST_STAGE.install=	do-configure
SUBST_MESSAGE.install=	Preparing INSTALL.pkgsrc file ...
SUBST_FILES.install=	INSTALL.pkgsrc
SUBST_SED.install=	-e 's,DOOMWADDIR,${PREFIX}/${DOOMWADDIR},'

TOOL_DEPENDS+=		dos2unix-[0-9]*:../../converters/dos2unix
WRKSRC=			${WRKDIR}/Shotgun_Symphony
NO_BUILD=		yes

do-patch:
	${MV} "${WRKDIR}/Shotgun Symphony" ${WRKSRC}
	cd ${WRKSRC} && dos2unix Sgnsym.txt
	cd ${WRKSRC} && dos2unix History.txt

pre-configure:
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKSRC}

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} sgnsym.wad		\
		${DESTDIR}${PREFIX}/${DOOMWADDIR}/Sgnsym.wad
	cd ${WRKSRC} && ${INSTALL_DATA} Sgnsym.txt		\
		${DESTDIR}${PREFIX}/${DOOMWADDIR}/Sgnsym.txt
	cd ${WRKSRC} && ${INSTALL_DATA} History.txt		\
		${DESTDIR}${PREFIX}/share/doc/doom-pwad-shotgun-symphony/History.txt
	cd ${WRKSRC} && ${INSTALL_DATA} INSTALL.pkgsrc		\
		${DESTDIR}${PREFIX}/share/doc/doom-pwad-shotgun-symphony/INSTALL.pkgsrc

.include "../../mk/bsd.pkg.mk"
