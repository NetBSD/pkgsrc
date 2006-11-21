# $NetBSD: Makefile,v 1.1.1.1 2006/11/21 13:44:14 wennmach Exp $

DISTNAME=		g95_source
VERSION=		0.91
PKGNAME=		g95-${VERSION}
PKGREVISION=		1
CATEGORIES=		lang
EXTRACT_SUFX.g95_source=	.tgz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX.g95_source}
DISTFILES+=		gcc-core-4.0.3.tar.gz
SITES.g95_source.tgz=	http://ftp.g95.org/
SITES.gcc-core-4.0.3.tar.gz= ftp://gcc.gnu.org/pub/gcc/releases/gcc-4.0.3/

MAINTAINER=		wennmach@NetBSD.org
HOMEPAGE=		http://www.g95.org/
COMMENT=		Fortran 95 compiler from g95.org

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake gzcat tar
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
PLIST_SUBST+=		MACHINE_GNU_PLATFORM=${MACHINE_GNU_PLATFORM:Q}

GCC_DIR=		${WRKDIR}/gcc-4.0.3
GCC_G95_DIR=		${GCC_DIR}/g95
GCC_CONFIGURE_SCRIPT=	../configure
GCC_CONFIGURE_ARGS=	${CONFIGURE_ARGS}
GCC_CONFIGURE_ARGS+=	--enable-languages=c

CONFIGURE_ARGS+=	--with-gcc-dir=${GCC_DIR}

post-extract:
	${MKDIR} ${GCC_G95_DIR}
	(cd ${WRKSRC}; ${GZCAT} libf95.a-${VERSION}.tar.gz | ${TAR} xpf -)

pre-configure:
	(cd ${GCC_G95_DIR}; ${GCC_CONFIGURE_SCRIPT} ${GCC_CONFIGURE_ARGS} && ${GMAKE})

post-build:
	(cd ${WRKSRC}/libf95.a-${VERSION}; ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} && ${GMAKE})

post-install:
	(cd ${WRKSRC}/libf95.a-${VERSION}; ${GMAKE} install)
	(cd ${PREFIX}/bin; ${LN} -sf ${MACHINE_GNU_PLATFORM:Q}-g95 g95)
	(cd ${PREFIX}/bin; ${LN} -sf ${MACHINE_GNU_PLATFORM:Q}-g95 f95)

.include "../../mk/bsd.pkg.mk"
