# $NetBSD: Makefile,v 1.9 2020/05/31 09:27:41 rillig Exp $

DISTNAME=		mintlib-CVS-20131219
PKGNAME=		cross-freemint-${DISTNAME:S/CVS-//}
PKGREVISION=		2
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-4.6.4/}
GCCNAME=		gcc-4.6.4
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${GCCNAME}.tar.bz2
MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		http://vincent.riviere.free.fr/soft/m68k-atari-mint/
COMMENT=		MiNTLib for FreeMiNT

SITES.mintlib-CVS-20131219.tar.gz=	http://vincent.riviere.free.fr/soft/m68k-atari-mint/archives/
WRKSRC=		${WRKDIR}

PATCH_SITES=	http://vincent.riviere.free.fr/soft/m68k-atari-mint/archives/
PATCHFILES=	gcc-4.6.4-mint-20130415.patch.bz2

# for http://gcc.gnu.org/bugzilla/attachment.cgi?id=15133 ,
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
TOOLS_PLATFORM.makeinfo=

TOOL_DEPENDS+=	cross-freemint-binutils-[0-9]*:../../cross/freemint-binutils

CHECK_PORTABILITY_SKIP+=	gcc-*/contrib/* # not needed

FREEMINT_PREFIX=	${PREFIX}/cross-freemint
CONFIGURE_DIRS=		${GCCNAME}bin
CONFIGURE_SCRIPT=	../${GCCNAME}/configure

USE_TOOLS+=		bash:run gmake makeinfo bison flex
TOOLS_BROKEN+=		perl
GNU_CONFIGURE=		yes

GNU_CONFIGURE_PREFIX=	${FREEMINT_PREFIX}

CFLAGS+=		-fomit-frame-pointer

CONFIGURE_ARGS+=	--target=m68k-atari-mint
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--disable-libstdcxx-pch
CONFIGURE_ARGS+=	--disable-nls
#CONFIGURE_ARGS+=	--disable-multilib

MAKE_ENV+=		SHELL=${TOOLS_PATH.bash}
MAKE_ENV+=		FREEMINT_PREFIX=${FREEMINT_PREFIX}
MAKE_ENV+=		WRKSRC=${WRKSRC}
MAKE_ENV+=		ARDIR=${FREEMINT_PREFIX}/bin
MAKE_ENV+=		DESTDIR=${DESTDIR}
MAKE_ENV+=		CONFIGURE_DIRS=${CONFIGURE_DIRS}
INFO_FILES=		yes

INSTALLATION_DIRS+=	bin

pre-configure:
	mkdir ${WRKSRC}/${CONFIGURE_DIRS}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/${GCCNAME}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/${GCCNAME}

do-build:
	cd ${WRKSRC}/${CONFIGURE_DIRS} && env ${MAKE_ENV} ${MAKE_PROGRAM} \
		${BUILD_MAKE_FLAGS} -f ${MAKE_FILE} all-gcc
	cd ${WRKSRC}/${CONFIGURE_DIRS} && env ${MAKE_ENV} ${MAKE_PROGRAM} \
		${BUILD_MAKE_FLAGS} -f ${MAKE_FILE} all-target-libgcc
	cd ${WRKSRC}/mintlib-CVS-20131219 && \
		echo "${WRKSRC}/${CONFIGURE_DIRS}/gcc/include -I${WRKSRC}/${CONFIGURE_DIRS}/gcc/include-fixed" > includepath
	cd ${WRKSRC}/mintlib-CVS-20131219 && env ${MAKE_ENV} \
		${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} -f ${MAKE_FILE}

do-install:
	cd ${WRKSRC}/mintlib-CVS-20131219 && env ${MAKE_ENV} \
		${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} -f ${MAKE_FILE} install

.include "../../cross/freemint-mintbin/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
