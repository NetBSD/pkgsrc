# $NetBSD: Makefile,v 1.98 2004/10/01 12:56:33 adam Exp $

DISTNAME=	netpbm-10.18.15
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netpbm/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://netpbm.sourceforge.net/
COMMENT=	Toolkit for conversion of images between different formats

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		lex make
USE_PERL5=		yes

INSTALL_TARGET=	install-dev install-run
MAKE_ENV+=	INSTALL="${INSTALL}" STRIPFLAG="${_STRIPFLAG_INSTALL}" \
		pkgdir="${STAGEDIR}"
MAKEFILE=	GNUmakefile
PLIST_SRC=	${WRKDIR}/PLIST_STAGE
REPLACE_PERL=	editor/ppmfade editor/ppmshadow editor/pnmquant \
		generator/ppmrainbow manweb
STAGEDIR=	${WRKDIR}/staging

LIBS.SunOS=	-lsocket -lnsl
MAKE_ENV+=	NETWORKLD="${LIBS}"

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif
.if ${MACHINE_ARCH} == "alpha"
GCC_REQD+=      3.0
.endif

pre-configure:
	${CP} ${WRKSRC}/Makefile.config.in ${WRKSRC}/Makefile.config

pre-install:
	${RM} -fr ${STAGEDIR}

post-install:
	cd ${STAGEDIR} && 					\
	${MV} link/* lib && 					\
	${RM} -rf link man/web && 				\
	${MKDIR} share/doc/netpbm &&				\
	${CP} ${WRKSRC}/doc/* share/doc/netpbm &&		\
	${MV} share/doc/netpbm/*.1	man/man1 &&		\
	${MV} misc share/netpbm && 				\
	${CHOWN} -R ${BINOWN}:${BINGRP} . &&			\
	${FIND} * \! -type d -print | ${SORT} >${PLIST_SRC} &&	\
	${FIND} * -type d -print | 				\
	while read DIR; do					\
	  ${TEST} -d "${PREFIX}/$${DIR}" ||			\
	    ${ECHO} "@dirrm $${DIR}";				\
	done >>${PLIST_SRC} &&					\
	${PAX} -rwpppm . ${PREFIX}
	${RM} -fr ${STAGEDIR}

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
