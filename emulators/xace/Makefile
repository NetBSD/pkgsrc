# $NetBSD: Makefile,v 1.1 2025/04/30 21:46:25 hauke Exp $

DISTNAME=	xAce-${PKGVER}
PKGNAME=	xace-${PKGVER}_2025-04-30
PKGVER=		0.5
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=lawrencewoodman/}
GITHUB_PROJECT=	xAce
GITHUB_TAG=	52d89b2044a729a751a7b9ddca995df7772cd3d8	# 2025-04-30

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://github.com/lawrencewoodman/xAce
COMMENT=	Jupiter ACE Z80 Forth Computer Emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_LANGUAGES=	c

DOCDIR=		share/doc/xace
ROMDIR=		share/xace

INSTALLATION_DIRS+=	bin ${DOCDIR} ${ROMDIR}

SUBST_CLASSES+=		rompath
SUBST_STAGE.rompath=	pre-configure
SUBST_MESSAGE.rompath=	Setting path to ROM file.
SUBST_FILES.rompath=	src/xmain.c
SUBST_SED.rompath=	-E -e "s,(ace.rom),${PREFIX}/${ROMDIR}/\1,g"

post-install:
.for dd in COPYING README.md xAce.png boldcomp.email.txt forth.txt
	${INSTALL_DATA} ${WRKSRC}/${dd} ${DESTDIR}${PREFIX}/${DOCDIR}/${dd}
.endfor
	${INSTALL_DATA} ${WRKSRC}/ace.rom ${DESTDIR}${PREFIX}/${ROMDIR}/

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
