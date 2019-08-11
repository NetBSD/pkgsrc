# $NetBSD: Makefile,v 1.32 2019/08/11 13:21:19 wiz Exp $

DISTNAME=	g95_source
PKGNAME=	g95-0.93
PKGREVISION=	12
CATEGORIES=	lang
MASTER_SITES=	http://ftp.g95.org/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DEFAULT_DISTFILES} gcc-core-${GCC_VER}.tar.bz2
SITES.gcc-core-4.1.2.tar.bz2=	${MASTER_SITE_GNU:=gcc/gcc-${GCC_VER}/}

MAINTAINER=	wennmach@NetBSD.org
HOMEPAGE=	http://www.g95.org/
COMMENT=	Fortran 95 compiler from g95.org
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake gtar automake autoconf
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gcc-dir=${GCC_DIR}
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
PLIST_SUBST+=		MACHINE_GNU_PLATFORM=${MACHINE_GNU_PLATFORM:Q}

GCC_VER=		4.1.2
GCC_DIR=		${WRKDIR}/gcc-${GCC_VER}
GCC_G95_DIR=		${GCC_DIR}/g95
GCC_CONFIGURE_SCRIPT=	../configure
GCC_CONFIGURE_ARGS=	${CONFIGURE_ARGS}
GCC_CONFIGURE_ARGS+=	--enable-languages=c
GCC_CONFIGURE_ARGS+=	--disable-multilib
GCC_CONFIGURE_ARGS+=	--disable-libssp # to build on NetBSD 6.99.43

# Avoid "ld: illegal text-relocation to half in .libs/x87.o"
LDFLAGS.Darwin+=	-Wl,-read_only_relocs,suppress

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.  if exists(/usr/lib/${MACHINE_ARCH}-linux-gnu)
MAKE_ENV+=             LIBRARY_PATH=/usr/lib/${MACHINE_ARCH}-linux-gnu
.  endif
MAKE_ENV+=             ac_cv_have_decl_asprintf=yes
USE_TOOLS+=            perl:build
.endif

.if ${OPSYS} == "SunOS"
GCC_CONFIGURE_ENV+=	OBJDUMP=/usr/sfw/bin/gobjdump
GCC_CONFIGURE_ARGS+=	--without-gnu-ld --with-ld=/usr/ccs/bin/ld
.  if !exists(/usr/sfw/bin/gas)
GCC_CONFIGURE_ARGS+=	--without-gnu-as --with-as=/usr/ccs/bin/as
.  else
GCC_CONFIGURE_ARGS+=	--with-gnu-as --with-as=/usr/sfw/bin/gas
.  endif
.endif

LIBGCC_SPEC=	${CC} -dumpspecs 2> /dev/null | grep -A 1 '^\*libgcc:$$' | tail -1

post-extract:
	${MKDIR} ${GCC_G95_DIR}
	cd ${WRKSRC} && ${GTAR} -xzf libf95.a-${PKGVERSION_NOREV}.tar.gz

pre-configure:
	mv ${GCC_DIR}/gcc/gcc.c ${GCC_DIR}/gcc/gcc.c.patched
	sed "s|%LIBGCC_SPEC%|\"${LIBGCC_SPEC:sh:Q}\"|" ${GCC_DIR}/gcc/gcc.c.patched > ${GCC_DIR}/gcc/gcc.c
	cd ${WRKSRC}/libf95.a-${PKGVERSION_NOREV} && autoreconf -i
	rm -f ${GCC_DIR}/config.sub ${GCC_DIR}/config.guess
	ln -fs ${PKGSRCDIR}/mk/gnu-config/config.sub ${GCC_DIR}/config.sub
	ln -fs ${PKGSRCDIR}/mk/gnu-config/config.guess ${GCC_DIR}/config.guess
	cd ${GCC_G95_DIR} && ${SETENV} ${CONFIGURE_ENV} ${GCC_CONFIGURE_SCRIPT} ${GCC_CONFIGURE_ARGS}
	cd ${GCC_G95_DIR} && ${SETENV} ${MAKE_ENV} ${GMAKE} -j${MAKE_JOBS:U1:Q}

post-build:
	cd ${WRKSRC}/libf95.a-${PKGVERSION_NOREV} && ${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
	cd ${WRKSRC}/libf95.a-${PKGVERSION_NOREV} && ${SETENV} ${MAKE_ENV} ${GMAKE} -j${MAKE_JOBS:U1:Q}

post-install:
	cd ${WRKSRC}/libf95.a-${PKGVERSION_NOREV} && ${GMAKE} install DESTDIR=${DESTDIR:Q}
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -sf ${MACHINE_GNU_PLATFORM:Q}-g95 g95
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -sf ${MACHINE_GNU_PLATFORM:Q}-g95 f95

.include "../../mk/bsd.pkg.mk"
