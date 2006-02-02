# $NetBSD: Makefile,v 1.129 2006/02/02 17:01:17 joerg Exp $

DISTNAME=	netpbm-10.31
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netpbm/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://netpbm.sourceforge.net/
COMMENT=	Toolkit for conversion of images between different formats

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	bash:run gmake lex perl

INSTALL_TARGET=	install-dev install-run
MAKE_ENV+=	INSTALL=${INSTALL:Q} STRIPFLAG=${_STRIPFLAG_INSTALL:Q} \
		pkgdir=${STAGEDIR:Q}
MAKEFILE=	GNUmakefile
PLIST_SRC=	${WRKDIR}/PLIST_STAGE
REPLACE_PERL=	editor/ppmfade editor/ppmshadow editor/pnmquant \
		generator/ppmrainbow manweb editor/pnmflip editor/ppmquant
STAGEDIR=	${WRKDIR}/staging

LIBS.SunOS+=	-lsocket -lnsl
MAKE_ENV+=	NETWORKLD=${LIBS:M*:Q}

# Several of the netpbm shell scripts use bashisms, so force using
# bash for all of the shell scripts.
#
SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	post-build
SUBST_SED.bash=		-e "1s|^\#!.*bin/sh|\#!${BASH}|"
SUBST_FILES.bash=	converter/other/anytopnm			\
			converter/other/pnmtoplainpnm			\
			converter/ppm/hpcdtoppm/hpcdtoppm		\
			converter/ppm/hpcdtoppm/pcdovtoppm		\
			editor/pamstretch-gen	editor/pnmindex		\
			editor/pnmmargin	editor/ppmquantall	\
			other/ppmtomap

.include "../../mk/bsd.prefs.mk"

# Fiasco fails to compile on Darwin-8.x.
.if !empty(MACHINE_PLATFORM:MDarwin-8.*-*)
MAKE_ENV+=	BUILD_FIASCO=N
.endif

MAKE_ENV+=	JASPERLIB="${LDFLAGS} -ljasper"
MAKE_ENV+=	JASPERHDR_DIR=${CPPFLAGS:M*:Q}

.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

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

.include "../../mk/bsd.pkg.mk"
