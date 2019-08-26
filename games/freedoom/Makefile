# $NetBSD: Makefile,v 1.1 2019/08/26 16:22:42 micha Exp $

DISTNAME=	freedoom-0.11.3
PKGREVISION=	1
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
SUBST_FILES.install=	INSTALL.pkgsrc
SUBST_SED.install=	-e 's,DOOMWADDIR,${PREFIX}/${DOOMWADDIR},'

NO_BUILD=		yes

pre-configure:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/freedoom1.wad \
		${DESTDIR}${PREFIX}/share/doom/freedoom1.wad
	${INSTALL_DATA} ${WRKSRC}/freedoom2.wad \
		${DESTDIR}${PREFIX}/share/doom/freedoom2.wad
	${INSTALL_DATA} ${WRKSRC}/INSTALL.pkgsrc \
		${DESTDIR}${PREFIX}/share/doc/freedoom/INSTALL.pkgsrc

.include "../../mk/bsd.pkg.mk"
