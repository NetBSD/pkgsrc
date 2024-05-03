# $NetBSD: Makefile,v 1.4 2024/05/03 09:53:28 micha Exp $

DISTNAME=	freedoom-0.13.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=freedoom/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://freedoom.github.io/
COMMENT=	Free content game for Doom engine
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	${DOOMWADDIR} share/doc/freedoom

# Configure INSTALL.pkgsrc (formerly displayed as MESSAGE)
SUBST_CLASSES+=		install
SUBST_STAGE.install=	do-configure
SUBST_MESSAGE.install=	Preparing INSTALL.pkgsrc file ...
SUBST_FILES.install=	${WRKDIR}/INSTALL.pkgsrc
SUBST_SED.install=	-e 's,DOOMWADDIR,${PREFIX}/${DOOMWADDIR},'

NO_BUILD=		yes

pre-configure:
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/freedoom1.wad \
		${DESTDIR}${PREFIX}/share/doom/freedoom1.wad
	${INSTALL_DATA} ${WRKSRC}/freedoom2.wad \
		${DESTDIR}${PREFIX}/share/doom/freedoom2.wad
	${INSTALL_DATA} ${WRKSRC}/freedoom-manual-en.pdf \
		${DESTDIR}${PREFIX}/share/doc/freedoom/freedoom-manual-en.pdf
	${INSTALL_DATA} ${WRKSRC}/freedoom-manual-es.pdf \
		${DESTDIR}${PREFIX}/share/doc/freedoom/freedoom-manual-es.pdf
	${INSTALL_DATA} ${WRKSRC}/freedoom-manual-fr.pdf \
		${DESTDIR}${PREFIX}/share/doc/freedoom/freedoom-manual-fr.pdf
	${INSTALL_DATA} ${WRKDIR}/INSTALL.pkgsrc \
		${DESTDIR}${PREFIX}/share/doc/freedoom/INSTALL.pkgsrc

.include "../../mk/bsd.pkg.mk"
