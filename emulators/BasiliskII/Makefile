# $NetBSD: Makefile,v 1.44 2020/04/15 22:54:38 joerg Exp $

DISTNAME=	BasiliskII-20190405
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=cebix/}
GITHUB_PROJECT=	macemu
GITHUB_TAG=	01052ca89d22882c870b84c5498cd0ee9a843b6b

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://basilisk.cebix.net/
COMMENT=	Open Source 68k Macintosh emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}/BasiliskII
CONFIGURE_DIRS=	src/Unix
BUILD_DIRS=	src/Unix

USE_LANGUAGES=	c c++
USE_TOOLS+=	aclocal autoheader autoconf automake
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_TOOLS+=	pkg-config gmake

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-fbdev-dga
CONFIGURE_ARGS+=	--disable-xf86-dga
CONFIGURE_ARGS+=	--disable-xf86-vidmode

CONFIGURE_ARGS+=	--enable-addressing=banks
CONFIGURE_ARGS+=	--without-mon
CONFIGURE_ARGS+=	--without-esd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--enable-macosx-gui
CONFIGURE_ARGS+=	--enable-macosx-sound
.else
post-extract:
	${RM} ${WRKSRC}/src/Unix/semaphore.h
.endif

.include "options.mk"

INSTALLATION_DIRS=	share/doc/BasiliskII

pre-configure:
	cd ${WRKSRC}/src/Unix && NO_CONFIGURE=x ./autogen.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/BasiliskII/
	${INSTALL_DATA} ${WRKSRC}/TECH ${DESTDIR}${PREFIX}/share/doc/BasiliskII/
	${INSTALL_DATA} ${WRKSRC}/TODO ${DESTDIR}${PREFIX}/share/doc/BasiliskII/

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
