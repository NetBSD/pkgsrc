# $NetBSD: Makefile,v 1.13 2012/10/03 12:55:13 asau Exp $
#

DISTNAME=	generator-0.35-cbiere-r4
PKGNAME=	generator-cbiere-0.35r4
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/cbiere/generator/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://squish.net/generator/
COMMENT=	Sega Mega drive genesis emulator (Improved)

MAKE_JOBS_SAFE=		no

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

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/generator-gtk \
		${DESTDIR}${PREFIX}/bin/generator-cbiere-gtk

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
