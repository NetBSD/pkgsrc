# $NetBSD: Makefile,v 1.50 2023/06/06 12:42:03 riastradh Exp $

DISTNAME=	xvidcore-1.3.7
CATEGORIES=	multimedia
MASTER_SITES=	https://downloads.xvid.com/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xvid.org/
COMMENT=	ISO MPEG-4 compliant video codec
LICENSE=	gnu-gpl-v2

USE_GCC_RUNTIME=	yes
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

# the resulting objects from the asm don't link correctly on Solaris.
# nor on amd64 -- they are not PIC, but the ABI demands it
# big patch available from Gentoo, if someone is interested:
# http://bugs.gentoo.org/show_bug.cgi?id=90287
.if ${OPSYS} == "SunOS" || ${MACHINE_ARCH} == "x86_64" || \
    !empty(MACHINE_PLATFORM:MDarwin-*-i386) || \
    !empty(MACHINE_PLATFORM:MNetBSD-[89].*-i386)
CONFIGURE_ARGS+=	--disable-assembly
.elif ${MACHINE_ARCH} == "i386"
TOOL_DEPENDS+=		nasm>=0.98.39nb3:../../devel/nasm
#.elif ${MACHINE_ARCH} == "x86_64"
#TOOL_DEPENDS+=	yasm>=0.4.0:../../devel/yasm
.endif

CFLAGS.SunOS+=		-D__inline=inline
SUBST_CLASSES.SunOS+=	ld
SUBST_MESSAGE.ld=	Fixing linker arguments for Solaris
SUBST_STAGE.ld=		pre-configure
SUBST_FILES.ld=		build/generic/configure
SUBST_SED.ld=		-e "s|-Wl,-soname,libxvidcore...(SHARED_EXTENSION)...(API_MAJOR)||"
SUBST_SED.ld+=		-e "s|-Wl,--version-script=libxvidcore.ld||"

WRKSRC=		${WRKDIR}/xvidcore
CONFIGURE_DIRS=	build/generic
GNU_CONFIGURE=	YES

MAKE_ENV+=	MKDIR=${MKDIR:Q}

.if ${OPSYS} == "Darwin"
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/libxvidcore.so.4
	${RM} -f ${DESTDIR}${PREFIX}/lib/libxvidcore.so
	${LN} -sf ${DESTDIR}${PREFIX}/lib/libxvidcore.4.dylib ${DESTDIR}${PREFIX}/lib/libxvidcore.dylib
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
