# $NetBSD: Makefile,v 1.219 2018/08/22 09:45:14 wiz Exp $

DISTNAME=	netpbm-10.79.04
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	#
# manually created from svn checkout of
# svn checkout http://svn.code.sf.net/p/netpbm/code/advanced netpbm
# tar --exclude netpbm/.svn -cvzf /archive/distfiles/netpbm-$VERSION.tar.gz netpbm
# where VERSION comes from reading netpbm/doc/HISTORY
# for the documentation:
# svn checkout http://svn.code.sf.net/p/netpbm/code/userguide netpbm-userguide
# cd netpbm-userguide && for i in *.html; do python2.7 ../netpbm/buildtools/makeman $i; done && cd ..
# tar -cvzf /archive/distfiles/netpbm-docs-r${SVN_REVISION}.tar.gz netpbm-userguide/*.[0-9]
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} netpbm-docs-r3052${EXTRACT_SUFX}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://netpbm.sourceforge.net/
COMMENT=	Toolkit for conversion of images between different formats
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake flex pax perl
USE_FEATURES=	snprintf

INSTALL_TARGET=	install-dev install-run
MAKE_ENV+=	INSTALL=${INSTALL:Q} STRIPFLAG=${_STRIPFLAG_INSTALL:Q} \
		pkgdir=${STAGEDIR} MACHINE=${MACHINE:Q}
MAKE_FLAGS+=	PKGMANDIR=${PKGMANDIR}
MAKE_FLAGS+=	CFLAGS_FOR_BUILD=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS_FOR_BUILD=${LDFLAGS:Q}
MAKE_FILE=	GNUmakefile
REPLACE_PERL+=	converter/pbm/pbmtox10bm
REPLACE_PERL+=	editor/pnmflip
REPLACE_PERL+=	editor/pnmquant
REPLACE_PERL+=	editor/ppmfade
REPLACE_PERL+=	editor/ppmquant
REPLACE_PERL+=	editor/ppmshadow
REPLACE_PERL+=	generator/ppmrainbow
REPLACE_PERL+=	manweb
REPLACE_SH+=	buildtools/stamp-date
STAGEDIR=	${WRKDIR}/staging
WRKSRC=		${WRKDIR}/netpbm

WRAPPER_REORDER_CMDS+=	reorder:l:rle:netpbm

SUBST_CLASSES+=		rgb_txt
SUBST_STAGE.rgb_txt=	pre-configure
SUBST_MESSAGE.rgb_txt=	Configure RGB_TXT
SUBST_FILES.rgb_txt=	config.mk
SUBST_SED.rgb_txt+=	-e 's,/usr/share/netpbm/rgb.txt,${PREFIX}/share/netpbm/rgb.txt,'

# needs pkg-config and x11?!
TEST_TARGET=	test

.include "../../mk/bsd.prefs.mk"

# only used if NEED_RUNTIME_PATH is set, so set it unconditionally
MAKE_FLAGS+=	NETPBMLIB_RUNTIME_PATH=${PREFIX}

MAKE_FLAGS.NetBSD+=	NEED_RUNTIME_PATH=Y
MAKE_FLAGS.Darwin+=	NETPBMLIBTYPE=dylib
MAKE_FLAGS.Darwin+=	NETPBMLIBSUFFIX=dylib
MAKE_FLAGS.SunOS+=	LDSHLIB=-shared
MAKE_FLAGS.SunOS+=	NEED_RUNTIME_PATH=Y
MAKE_FLAGS.SunOS+=	NETWORKLD="-lsocket -lnsl"

.if ${OS_VARIANT} == "SCOOSR5"
MAKE_FLAGS+=	NETWORKLD="-lsocket -lresolv"
.endif

.include "../../mk/compiler.mk"

# Ridiculous but they hardcode it in every file so we have no choice.
.if ${OPSYS} == "SunOS" && \
    (!empty(CC_VERSION:Mgcc-[6-9]*) || !empty(PKGSRC_COMPILER:Mclang))
SUBST_CLASSES+=		xopen
SUBST_STAGE.xopen=	pre-configure
SUBST_FILES.xopen=	*.c */*.c */*/*.c */*/*/*.c */*/*/*/*.c */*/*/*/*/*.c
SUBST_FILES.xopen+=	lib/util/lexheader
SUBST_SED.xopen=	-e '/_XOPEN_SOURCE/s/500/600/'
SUBST_SED.xopen+=	-e '/_XOPEN_SOURCE/s/1$$/600/'
SUBST_SED.xopen+=	-e '/_XOPEN_SOURCE[^0-9]*\//s/SOURCE/SOURCE 600/'
SUBST_SED.xopen+=	-e '/_XOPEN_SOURCE$$/s/E$$/E 600/'
SUBST_SED.xopen+=	-e '/_POSIX_SOURCE.*fdopen/s/_POSIX_SOURCE/_XOPEN_SOURCE 600/'
.endif

INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man3 ${PKGMANDIR}/man5 share/netpbm

post-extract:
	cd ${WRKSRC} && ${CP} config.mk.in config.mk
	${ECHO} "CFLAGS_SHLIB = -fPIC" >> ${WRKSRC}/config.mk
	${ECHO} "JPEGLIB = ${BUILDLINK_PREFIX.jpeg}/lib/libjpeg.so" >> ${WRKSRC}/config.mk
	${ECHO} "JPEGHDR_DIR = ${BUILDLINK_PREFIX.jpeg}/include" >> ${WRKSRC}/config.mk
	${ECHO} "TIFFLIB = ${BUILDLINK_PREFIX.tiff}/lib/libtiff.so" >> ${WRKSRC}/config.mk
	${ECHO} "TIFFHDR_DIR = ${BUILDLINK_PREFIX.tiff}/include" >> ${WRKSRC}/config.mk
	${ECHO} "ZLIB = ${BUILDLINK_PREFIX.zlib}/lib/libz.so" >> ${WRKSRC}/config.mk
	${ECHO} "ZHDR_DIR = ${BUILDLINK_PREFIX.zlib}/include" >> ${WRKSRC}/config.mk
.if ${OPSYS} == "Darwin"
	${ECHO} 'LDSHLIB=-dynamiclib -install_name $$(PREFIX)/lib/libnetpbm.$$(MAJ).dylib -compatibility_version $$(MAJ) -current_version $$(MAJ).$$(MIN)' >> ${WRKSRC}/config.mk
.endif

pre-install:
	${RM} -fr ${STAGEDIR}
	${MKDIR} -p ${STAGEDIR}/man/web

post-install:
	cd ${STAGEDIR} && 					\
	${RM} -rf ${PKGMANDIR}/web && 				\
	${RM} -rf man/web && 					\
	${MKDIR} share &&					\
	${MV} misc share/netpbm && 				\
	${CHOWN} -R ${BINOWN}:${BINGRP} . &&			\
	pax -rwpppm . ${DESTDIR}${PREFIX}
	${RM} -fr ${STAGEDIR}
	${INSTALL_DATA} ${WRKDIR}/netpbm-userguide/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKDIR}/netpbm-userguide/*.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_DATA} ${WRKDIR}/netpbm-userguide/*.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
