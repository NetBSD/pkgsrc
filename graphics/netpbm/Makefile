# $NetBSD: Makefile,v 1.80 2003/09/17 19:40:35 grant Exp $

DISTNAME=	netpbm-10.11.8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netpbm/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://netpbm.sourceforge.net/
COMMENT=	Toolkit for conversion of images between different formats

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

INSTALL_TARGET=	install-dev install-run
MAKE_ENV+=	INSTALL="${INSTALL}" STRIPFLAG="${_STRIPFLAG_INSTALL}" \
		pkgdir="${STAGEDIR}"
MAKEFILE=	GNUmakefile
PLIST_SRC=	${WRKDIR}/PLIST_STAGE
REPLACE_PERL=	editor/ppmfade editor/ppmshadow editor/pnmquant \
		generator/ppmrainbow manweb
STAGEDIR=	${WRKDIR}/staging

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
USE_PKGSRC_GCC=		# defined
.endif

.if (${OPSYS} == SunOS)
MAKE_ENV+=	NETWORKLD="-lsocket -lnsl"
BUILD_DEPENDS+=	flex>=2.5.4:../../devel/flex
.else
MAKE_ENV+=	NETWORKLD=""
.endif

.if ${OPSYS} == Linux && !exists(/usr/bin/flex)
BUILD_DEPENDS+=	flex>=2.5.4:../../devel/flex
.endif

pre-configure:
	${CP} ${WRKSRC}/Makefile.config.in ${WRKSRC}/Makefile.config

pre-install:
	${RM} -fr ${STAGEDIR}

post-install:
	cd ${STAGEDIR} && 				\
	${MV} link/* lib && 				\
	${RM} -rf link man/web && 			\
	${MKDIR} share/doc/netpbm &&			\
	${CP} ${WRKSRC}/doc/* share/doc/netpbm &&	\
	${MV} share/doc/netpbm/*.1	man/man1 &&	\
	${MV} misc share/netpbm && 			\
	${CHOWN} -R ${BINOWN}:${BINGRP} . &&		\
	${FIND} * \! -type d | ${SORT} >${PLIST_SRC} &&	\
	${FIND} * -type d | 				\
	while read DIR; do				\
	  ${TEST} -d "${PREFIX}/$${DIR}" ||		\
	    ${ECHO} "@dirrm $${DIR}";			\
	done >>${PLIST_SRC} &&				\
	${GTAR} -cf - * | ${GTAR} -xpC ${PREFIX} -f -
	${RM} -fr ${STAGEDIR}

.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
