# $NetBSD: Makefile,v 1.30 2007/12/17 22:13:42 tron Exp $

DISTNAME=	xvidcore-1.1.3
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xvid.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xvid.org/
COMMENT=	ISO MPEG-4 compliant video codec

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

# the resulting objects from the asm don't link correctly on Solaris.
# nor on amd64 -- they are not PIC, but the ABI demands it
# big patch available from Gentoo, if someone is interested:
# http://bugs.gentoo.org/show_bug.cgi?id=90287
.if ${OPSYS} == "SunOS" || ${MACHINE_ARCH} == "x86_64" || \
    !empty(MACHINE_PLATFORM:MDarwin-[9].*-i386)
CONFIGURE_ARGS+=	--disable-assembly
.elif ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=		nasm>=0.98.39nb3:../../devel/nasm
#.elif ${MACHINE_ARCH} == "x86_64"
#BUILD_DEPENDS+=		yasm>=0.4.0:../../devel/yasm
.endif

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME}/build/generic
GNU_CONFIGURE=	YES

MAKE_ENV+=	MKDIR=${MKDIR:Q}

.if ${OPSYS} == "Darwin"
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/libxvidcore.so.4
	${MV} -f ${DESTDIR}${PREFIX}/lib/libxvidcore.so ${DESTDIR}${PREFIX}/lib/libxvidcore.dylib
.endif

.include "../../mk/bsd.pkg.mk"
