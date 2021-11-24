# $NetBSD: Makefile,v 1.21 2021/11/24 12:05:18 wiz Exp $

DISTNAME=		ucon64-2.2.2-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ucon64/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ucon64.sourceforge.io/
COMMENT=		Emulator ROM and disk image converter and inspector
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${DISTNAME}/src

.include "../../mk/bsd.prefs.mk"

# parallel port I/O works on i386 and x86_64, but cannot work on macOS, even on Intel
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64") && ${OPSYS} != "Darwin"
# --enable-parallel is default
CONFIGURE_ARGS+=	--with-libcd64
.else
# --without-libcd64 is default
CONFIGURE_ARGS+=	--disable-parallel
.endif

GNU_CONFIGURE=			yes
USE_TOOLS+=			gmake
CHECK_PORTABILITY_SKIP+=	install_beos.sh

INSTALLATION_DIRS=	bin share/doc/ucon64/images

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ucon64 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/*.html \
		${DESTDIR}${PREFIX}/share/doc/ucon64
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/images/* \
		${DESTDIR}${PREFIX}/share/doc/ucon64/images

.include "options.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
