# $NetBSD: Makefile,v 1.2 2020/04/30 16:06:41 micha Exp $

DISTNAME=		preacher
# Use release date from preacher.txt as package version
PKGNAME=		doom2-pwad-${DISTNAME}-20181129
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.fu-berlin.de/pc/games/idgames/levels/doom2/Ports/p-r/
MASTER_SITES+=		ftp://mirrors.syringanetworks.net/idgames/levels/doom2/Ports/p-r/
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_SUFX=		.zip

MAINTAINER=		micha@NetBSD.org
COMMENT=		Doom II mod
LICENSE=		doom-pwad-license

.include "../../mk/bsd.prefs.mk"

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	${DOOMWADDIR} share/doc/doom2-pwad-${DISTNAME}

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
		${INSTALL_DATA} PREACHER.wad				\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/PREACHER.wad;	\
		${INSTALL_DATA} preacher.txt				\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/PREACHER.txt
	cd ${WRKSRC} &&							\
		${INSTALL_DATA} INSTALL.pkgsrc				\
			${DESTDIR}${PREFIX}/share/doc/doom2-pwad-${DISTNAME}/INSTALL.pkgsrc

.include "../../mk/bsd.pkg.mk"
