# $NetBSD: Makefile,v 1.16 2004/04/28 05:06:28 snj Exp $

DISTNAME=		rs-0.7.3.2
PKGNAME=		RScheme-0.7.3.2
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.rscheme.org/pub/rscheme/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.rscheme.org/
COMMENT=		Object-oriented Scheme implementation

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
ALL_TARGET=		base

NOT_FOR_PLATFORM=       *-*-alpha

RSCHEME_MODULES_DIR=	src/install/resource/modules
RSCHEME_MODULES=	${RSCHEME_MODULES_DIR}/primops.mif ${RSCHEME_MODULES_DIR}/precore.mif \
			${RSCHEME_MODULES_DIR}/corelib.mif ${RSCHEME_MODULES_DIR}/low_scheme.mif \
			${RSCHEME_MODULES_DIR}/objsys.mif ${RSCHEME_MODULES_DIR}/paths.mif \
			${RSCHEME_MODULES_DIR}/mathlib.mif ${RSCHEME_MODULES_DIR}/tables.mif \
			${RSCHEME_MODULES_DIR}/iolib.mif ${RSCHEME_MODULES_DIR}/high_scheme.mif \
			${RSCHEME_MODULES_DIR}/start.mif ${RSCHEME_MODULES_DIR}/sort.mif \
			${RSCHEME_MODULES_DIR}/imageio.mif ${RSCHEME_MODULES_DIR}/editinp.mif \
			${RSCHEME_MODULES_DIR}/mlink.mif ${RSCHEME_MODULES_DIR}/compiler.mif \
			${RSCHEME_MODULES_DIR}/codegen.mif ${RSCHEME_MODULES_DIR}/repl.mif \
			${RSCHEME_MODULES_DIR}/debugger.mif ${RSCHEME_MODULES_DIR}/regex.mif \
			${RSCHEME_MODULES_DIR}/hacks.mif ${RSCHEME_MODULES_DIR}/threads.mif

pre-configure:
	@cd ${WRKSRC}/stage0 && ${AUTOCONF}
	cd ${WRKSRC}/stage0 && ${SETENV} ${CONFIGURE_ENV} CFLAGS="${CFLAGS}" \
		./configure ${CONFIGURE_ARGS} --prefix=`pwd`/install
	@cd ${WRKSRC}/stage0 && ${SETENV} ${MAKE_ENV} ${MAKE}
	@${MKDIR} ${WRKSRC}/stage0/install/bin
	@cd ${WRKSRC}/stage0 && ${SETENV} ${MAKE_ENV} ${MAKE} shell
	@cd ${WRKSRC}/stage0 && ${LN} -fs ../../rshell/rs install/bin/rs
	@cd ${WRKSRC}/stage0 && ${LN} -fs ../../system.img install/resource/system.img
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE}	RS=${WRKSRC}/stage0/install/bin/rs \
			RSC_FLAGS2=-ccode src src/tmp/rsc.img \
			${RSCHEME_MODULES} src/tmp/system.bas
	@cd ${WRKSRC} && ${CP} -p stage0/configure src/configure

do-configure:
	@cd ${WRKSRC}/src && ${SETENV} ${CONFIGURE_ENV} CFLAGS="${CFLAGS}" \
		./configure ${CONFIGURE_ARGS} --prefix=${PREFIX}/lib/rscheme \
				--enable-readline --enable-dynamic-linking

do-build:
	@cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET}

do-install:
	cd ${WRKSRC}/src && \
		(cd install; ${PAX} -rw include ${BUILDLINK_DIR}) && \
		(cd install; ${PAX} -rw lib ${BUILDLINK_DIR}) && \
		${SETENV} ${MAKE_ENV} ${MAKE} install-base && \
		${SETENV} ${MAKE_ENV} ${MAKE} shell && \
		${MAKE} install-shell && \
		${MAKE} packages

post-install:
	${RM} -f ${PREFIX}/bin/rscheme
	${LN} -s ${PREFIX}/lib/rscheme/bin/rs ${PREFIX}/bin/rscheme
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rscheme
	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/README \
		${PREFIX}/share/doc/rscheme
	${RM} -rf ${BUILDLINK_DIR}/include/rscheme			\
		${BUILDLINK_DIR}/include/rscheme.h			\
		${BUILDLINK_DIR}/lib/librs.a
	${CHMOD} -R g+w ${WRKSRC}

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
