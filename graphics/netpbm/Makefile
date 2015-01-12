# $NetBSD: Makefile,v 1.200 2015/01/12 11:47:59 is Exp $

DISTNAME=	netpbm-10.68.02
CATEGORIES=	graphics
MASTER_SITES=	#
PKGREVISION=	1
# manually created from svn checkout of
# svn checkout http://svn.code.sf.net/p/netpbm/code/advanced netpbm
# tar --exclude netpbm/.svn/\* -cvzf /archive/distfiles/netpbm-$VERSION.tar.gz netpbm
# where VERSION comes from reading netpbm/doc/HISTORY
# for the documentation:
# svn checkout http://svn.code.sf.net/p/netpbm/code/userguide netpbm-userguide
# cd netpbm-userguide && for i in *.html; do python2.7 ../netpbm/buildtools/makeman $i; done && cd ..
# tar -cvzf /archive/distfiles/netpbm-docs-r${SVN_REVISION}.tar.gz netpbm-userguide/*.[0-9]
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} netpbm-docs-r2313${EXTRACT_SUFX}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://netpbm.sourceforge.net/
COMMENT=	Toolkit for conversion of images between different formats
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake lex pax perl
USE_FEATURES=	snprintf

INSTALL_TARGET=	install-dev install-run
MAKE_ENV+=	INSTALL=${INSTALL:Q} STRIPFLAG=${_STRIPFLAG_INSTALL:Q} \
		pkgdir=${STAGEDIR:Q} MACHINE=${MACHINE:Q}
MAKE_FILE=	GNUmakefile
REPLACE_PERL+=	converter/pbm/pbmtox10bm
REPLACE_PERL+=	editor/pnmflip
REPLACE_PERL+=	editor/pnmquant
REPLACE_PERL+=	editor/ppmfade
REPLACE_PERL+=	editor/ppmquant
REPLACE_PERL+=	editor/ppmshadow
REPLACE_PERL+=	generator/ppmrainbow
REPLACE_PERL+=	manweb
STAGEDIR=	${WRKDIR}/staging
WRKSRC=		${WRKDIR}/netpbm

WRAPPER_REORDER_CMDS+=	reorder:l:rle:netpbm

SUBST_CLASSES+=		rgb_txt
SUBST_STAGE.rgb_txt=	post-patch
SUBST_MESSAGE.rgb_txt=	Configure RGB_TXT
SUBST_FILES.rgb_txt=	config.mk
SUBST_SED.rgb_txt+=	-e 's,/usr/share/netpbm/rgb.txt,${PREFIX}/share/netpbm/rgb.txt,'

.include "../../mk/bsd.prefs.mk"

# only used if NEED_RUNTIME_PATH is set, so set it unconditionally
MAKE_FLAGS+=	NETPBMLIB_RUNTIME_PATH=${PREFIX}

.if ${OPSYS} == "NetBSD"
MAKE_FLAGS+=	NEED_RUNTIME_PATH=Y
.elif ${OPSYS} == "Darwin"
MAKE_FLAGS+=	NETPBMLIBTYPE=dylib
MAKE_FLAGS+=	NETPBMLIBSUFFIX=dylib
.elif ${OPSYS} == "SunOS"
MAKE_FLAGS+=	LDSHLIB=-shared
MAKE_FLAGS+=	NEED_RUNTIME_PATH=Y
MAKE_FLAGS+=	NETWORKLD="-lsocket -lnsl"
.elif ${OS_VARIANT} == "SCOOSR5"
MAKE_FLAGS+=	NETWORKLD="-lsocket -lresolv"
.endif

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/netpbm

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

post-install:
	cd ${STAGEDIR} && 					\
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
