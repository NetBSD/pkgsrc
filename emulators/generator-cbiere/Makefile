# $NetBSD: Makefile,v 1.2 2005/10/02 22:06:06 wiz Exp $
#

DISTNAME=	generator-0.35-cbiere-r2
PKGNAME=	generator-cbiere-0.35r2
CATEGORIES=	emulators
MASTER_SITES=	http://www.ghostwhitecrab.de/generator/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ghostwhitecrab.de/generator/
COMMENT=	Sega Mega drive genesis emulator (Improved)

GNU_CONFIGURE=		yes

.if (${MACHINE_ARCH} == "i386")
BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm
CONFIGURE_ARGS+=	--with-gtk --with-raze
.else
CONFIGURE_ARGS+=	--with-gtk --with-cmz80
.endif

CONFIGURE_ARGS+=	--with-sdl-audio

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DBYTES_HIGHFIRST
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/generator-gtk \
		${PREFIX}/bin/generator-cbiere-gtk

.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
