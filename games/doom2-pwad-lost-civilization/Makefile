# $NetBSD: Makefile,v 1.1 2020/05/20 16:31:07 micha Exp $

VERS=			15
DISTNAME=		joi_lstcv${VERS}
PKGNAME=		doom2-pwad-lost-civilization-${VERS}
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.fu-berlin.de/pc/games/idgames/levels/doom2/Ports/megawads/
MASTER_SITES+=		ftp://mirrors.syringanetworks.net/idgames/levels/doom2/Ports/megawads/
EXTRACT_SUFX=		.zip

MAINTAINER=		micha@NetBSD.org
COMMENT=		Doom II mod
LICENSE=		doom-pwad-license

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	${DOOMWADDIR} share/doc/doom2-pwad-lost-civilization

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
	cd "${WRKSRC}" && dos2unix joi_lstcv${VERS}.txt

pre-configure:
	${CP} ${FILESDIR}/INSTALL.pkgsrc "${WRKSRC}"

do-install:
	cd "${WRKSRC}" && ${INSTALL_DATA} joi_lstcv${VERS}.wad		\
		${DESTDIR}${PREFIX}/${DOOMWADDIR}/Joi_lstcv.wad
	cd "${WRKSRC}" && ${INSTALL_DATA} joi_lstcv${VERS}.txt		\
		${DESTDIR}${PREFIX}/${DOOMWADDIR}/Joi_lstcv.txt
	cd "${WRKSRC}" && ${INSTALL_DATA} INSTALL.pkgsrc		\
		${DESTDIR}${PREFIX}/share/doc/doom2-pwad-lost-civilization/INSTALL.pkgsrc

.include "../../mk/bsd.pkg.mk"
