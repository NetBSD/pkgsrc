# $NetBSD: Makefile,v 1.2 2015/11/25 12:49:12 jperkin Exp $

DISTNAME=		pml-2.03
PKGNAME=		cross-freemint-${DISTNAME}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-4.6.4/}
GCCNAME=		gcc-4.6.4
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${GCCNAME}.tar.bz2

SITES.pml-2.03.tar.bz2=	http://vincent.riviere.free.fr/soft/m68k-atari-mint/archives/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		http://vincent.riviere.free.fr/soft/m68k-atari-mint/
COMMENT=		PML math library for FreeMiNT
EXTRACT_SUFX=		.tar.bz2

WRKSRC=		${WRKDIR}

PATCH_SITES=	http://vincent.riviere.free.fr/soft/m68k-atari-mint/archives/
PATCHFILES=	gcc-4.6.4-mint-20130415.patch.bz2
PATCHFILES+=	pml-2.03-mint-20110207.patch.bz2

# for http://gcc.gnu.org/bugzilla/attachment.cgi?id=15133 ,
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
TOOLS_PLATFORM.makeinfo=

DEPENDS+=	cross-freemint-binutils-[0-9]*:../../cross/freemint-binutils
DEPENDS+=	cross-freemint-mintbin-[0-9]*:../../cross/freemint-mintbin

FREEMINT_PREFIX=	${PREFIX}/cross-freemint
CONFIGURE_DIRS=		${GCCNAME}bin
CONFIGURE_SCRIPT=	../${GCCNAME}/configure

USE_TOOLS+=		bash:run gmake makeinfo
GNU_CONFIGURE=		yes

GNU_CONFIGURE_PREFIX=	${FREEMINT_PREFIX}

CFLAGS+=		-fomit-frame-pointer

CROSSDIR=		${DESTDIR}${FREEMINT_PREFIX}/m68k-atari-mint

CONFIGURE_ARGS+=	--target=m68k-atari-mint
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--disable-libstdcxx-pch
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-multilib

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
#	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/${GCCNAME}
#	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/${GCCNAME}

# XXX I cannot split build and install. This should be improved.
do-build:
	cd ${WRKSRC}/${CONFIGURE_DIRS} && env ${MAKE_ENV} ${MAKE_PROGRAM} \
		${BUILD_MAKE_FLAGS} -f ${MAKE_FILE} all-gcc
	cd ${WRKSRC}/${CONFIGURE_DIRS} && env ${MAKE_ENV} ${MAKE_PROGRAM} \
		${BUILD_MAKE_FLAGS} -f ${MAKE_FILE} all-target-libgcc
	cd ${WRKSRC}/pml-2.03/pmlsrc && env ${MAKE_ENV} \
		${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		CROSSDIR=${CROSSDIR} -f ${MAKE_FILE}
	cd ${WRKSRC}/pml-2.03/pmlsrc && env ${MAKE_ENV} CFLAGS+=-m68020-60 \
		${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		CROSSDIR=${CROSSDIR} \
		CROSSLIB=${CROSSDIR}/m68020-60 -f ${MAKE_FILE}
	cd ${WRKSRC}/pml-2.03/pmlsrc && env ${MAKE_ENV} CFLAGS+=-mcpu=5475\
		${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		CROSSDIR=${CROSSDIR} \
		CROSSLIB=${CROSSDIR}/m5475 -f ${MAKE_FILE}

do-install:
	cd ${WRKSRC}/pml-2.03/pmlsrc && env ${MAKE_ENV} \
		${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		CROSSDIR=${CROSSDIR} -f ${MAKE_FILE} install
	cd ${WRKSRC}/pml-2.03/pmlsrc && env ${MAKE_ENV} CFLAGS+=-m68020-60 \
		${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		CROSSDIR=${CROSSDIR} \
		CROSSLIB=${CROSSDIR}/m68020-60 -f ${MAKE_FILE} install
	cd ${WRKSRC}/pml-2.03/pmlsrc && env ${MAKE_ENV} CFLAGS+=-mcpu=5475\
		${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		CROSSDIR=${CROSSDIR} \
		CROSSLIB=${CROSSDIR}/m5475 -f ${MAKE_FILE} install

.include "../../cross/freemint-mintlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
