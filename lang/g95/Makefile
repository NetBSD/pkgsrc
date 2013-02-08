# $NetBSD: Makefile,v 1.14 2013/02/08 12:46:14 obache Exp $

DISTNAME=		g95_source
VERSION=		0.93
PKGNAME=		g95-${VERSION}
CATEGORIES=		lang
MASTER_SITES=		http://ftp.g95.org/v${VERSION}/
EXTRACT_SUFX=		.tgz
DIST_SUBDIR=		${PKGNAME_NOREV}
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		gcc-core-4.0.3.tar.bz2
SITES.gcc-core-4.0.3.tar.bz2=	${MASTER_SITE_GNU:=gcc/gcc-4.0.3/}

MAINTAINER=		wennmach@NetBSD.org
HOMEPAGE=		http://www.g95.org/
COMMENT=		Fortran 95 compiler from g95.org

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake gtar
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
PLIST_SUBST+=		MACHINE_GNU_PLATFORM=${MACHINE_GNU_PLATFORM:Q}

GCC_DIR=		${WRKDIR}/gcc-4.0.3
GCC_G95_DIR=		${GCC_DIR}/g95
GCC_CONFIGURE_SCRIPT=	../configure
GCC_CONFIGURE_ARGS=	${CONFIGURE_ARGS}
GCC_CONFIGURE_ARGS+=	--enable-languages=c
GCC_CONFIGURE_ARGS+=	--disable-multilib

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
GCC_CONFIGURE_ENV+=	OBJDUMP=/usr/sfw/bin/gobjdump
GCC_CONFIGURE_ARGS+=	--without-gnu-ld --with-ld=/usr/ccs/bin/ld
. if !exists(/usr/sfw/bin/gas)
GCC_CONFIGURE_ARGS+=	--without-gnu-as --with-as=/usr/ccs/bin/as
. else
GCC_CONFIGURE_ARGS+=	--with-gnu-as --with-as=/usr/sfw/bin/gas
. endif
.endif

CONFIGURE_ARGS+=	--with-gcc-dir=${GCC_DIR}

post-extract:
	${MKDIR} ${GCC_G95_DIR}
	cd ${WRKSRC} && ${GTAR} -xzf libf95.a-${VERSION}.tar.gz

pre-configure:
	rm -f ${GCC_DIR}/config.sub ${GCC_DIR}/config.guess
	ln -fs ${PKGSRCDIR}/mk/gnu-config/config.sub ${GCC_DIR}/config.sub
	ln -fs ${PKGSRCDIR}/mk/gnu-config/config.guess ${GCC_DIR}/config.guess
	cd ${GCC_G95_DIR} && ${GCC_CONFIGURE_SCRIPT} ${GCC_CONFIGURE_ARGS} && ${GMAKE}

post-build:
	cd ${WRKSRC}/libf95.a-${VERSION} && ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} && ${GMAKE}

post-install:
	cd ${WRKSRC}/libf95.a-${VERSION} && ${GMAKE} install DESTDIR=${DESTDIR:Q}
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -sf ${MACHINE_GNU_PLATFORM:Q}-g95 g95
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -sf ${MACHINE_GNU_PLATFORM:Q}-g95 f95

.include "../../mk/bsd.pkg.mk"
