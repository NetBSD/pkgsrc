# $NetBSD: Makefile,v 1.185 2014/07/17 15:52:25 ryoon Exp $

DISTNAME=	netpbm-10.35.80
PKGREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netpbm/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://netpbm.sourceforge.net/
COMMENT=	Toolkit for conversion of images between different formats
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	bash:run gmake lex pax perl
USE_FEATURES=	snprintf
USE_GCC_RUNTIME=yes

INSTALL_TARGET=	install-dev install-run
MAKE_ENV+=	INSTALL=${INSTALL:Q} STRIPFLAG=${_STRIPFLAG_INSTALL:Q} \
		pkgdir=${STAGEDIR:Q} MACHINE=${MACHINE:Q}
MAKE_FILE=	GNUmakefile
REPLACE_PERL+=	editor/ppmfade editor/ppmshadow editor/pnmquant \
		generator/ppmrainbow manweb editor/pnmflip editor/ppmquant
STAGEDIR=	${WRKDIR}/staging

LIBS.SunOS+=	-lsocket -lnsl
MAKE_ENV+=	NETWORKLD=${LIBS:Q}
MAKE_FLAGS+=	PKGMANDIR=${PKGMANDIR}

WRAPPER_REORDER_CMDS+=	reorder:l:rle:netpbm

# Several of the netpbm shell scripts use bashisms, so force using
# bash for all of the shell scripts.
REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/sh
REPLACE.bash.new=	${TOOLS_PATH.bash}
REPLACE_FILES.bash=	converter/other/anytopnm
REPLACE_FILES.bash+=	converter/other/pnmtoplainpnm
REPLACE_FILES.bash+=	converter/ppm/hpcdtoppm/hpcdtoppm
REPLACE_FILES.bash+=	converter/ppm/hpcdtoppm/pcdovtoppm
REPLACE_FILES.bash+=	editor/pamstretch-gen
REPLACE_FILES.bash+=	editor/pnmindex.sh
REPLACE_FILES.bash+=	editor/pnmmargin
REPLACE_FILES.bash+=	editor/ppmquantall
REPLACE_FILES.bash+=	other/ppmtomap

SUBST_CLASSES+=		rgb_txt
SUBST_STAGE.rgb_txt=	post-patch
SUBST_MESSAGE.rgb_txt=	Configure RGB_TXT
SUBST_FILES.rgb_txt=	pm_config.in.h
SUBST_SED.rgb_txt+=	-e 's,@@PREFIX@@,${PREFIX},'

.include "../../mk/bsd.prefs.mk"

# Fiasco fails to compile on Darwin-8.x.
PLIST_VARS+=	fiasco
.if !empty(MACHINE_PLATFORM:MDarwin-8.*-*)
MAKE_ENV+=	BUILD_FIASCO=N
.else
PLIST.fiasco=	yes
.endif

.if ${OPSYS} == "Darwin"
MAKE_ENV+=	NETPBMLIBTYPE="dylib" NETPBMLIBSUFFIX="dylib"
.elif ${OPSYS} == "HPUX" && ${OBJECT_FMT} == "SOM"
MAKE_ENV+=	NETPBMLIBTYPE="unixshared" NETPBMLIBSUFFIX="sl"
.else
MAKE_ENV+=	NETPBMLIBTYPE="unixshared" NETPBMLIBSUFFIX="so"
.endif

.if ${OS_VARIANT} == "SCOOSR5"
LDFLAGS.SCO_SV+=	-lsocket
.endif

.if !empty(PKGSRC_COMPILER:Mido)
CPPFLAGS+=	-DSGI_IDO_CC
.endif

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/netpbm

pre-configure:
	${CP} ${WRKSRC}/Makefile.config.in ${WRKSRC}/Makefile.config

pre-install:
	${RM} -fr ${STAGEDIR}

post-install:
	cd ${STAGEDIR} && 					\
	${MV} link/* lib && 					\
	${RM} -rf link man/web && 				\
	${MKDIR} share &&					\
	${MV} misc share/netpbm && 				\
	${CHOWN} -R ${BINOWN}:${BINGRP} . &&			\
	pax -rwpppm . ${DESTDIR}${PREFIX}
	${RM} -fr ${STAGEDIR}

.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
