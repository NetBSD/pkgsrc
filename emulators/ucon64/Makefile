# $NetBSD: Makefile,v 1.20 2021/05/08 15:18:37 nia Exp $

DISTNAME=		ucon64-2.2.1-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ucon64/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ucon64.sourceforge.io/
COMMENT=		Emulator ROM and disk image converter and inspector
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${DISTNAME}/src

.include "../../mk/bsd.prefs.mk"

# code assumes 64-bit target on NetBSD
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} != "i386"
CONFIGURE_ARGS+=		--with-libcd64
.endif

# parallel port I/O cannot work on macOS, even on Intel
.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=		--disable-parallel
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
