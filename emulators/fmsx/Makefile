# $NetBSD: Makefile,v 1.31 2016/03/01 20:16:52 joerg Exp $

DISTNAME=	fMSX351
PKGNAME=	fmsx-3.5.1
PKGREVISION=	1
CATEGORIES=	emulators x11
MASTER_SITES=	http://fms.komkon.org/fMSX/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fms.komkon.org/fMSX/
COMMENT=	MSX (Z80-based computer) emulator

RESTRICTED=		ROM image copyright is questionable
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

WRKSRC=	${WRKDIR}

BUILD_DIRS=	fMSX/Unix

.include "../../mk/bsd.prefs.mk"
.include "../../mk/endian.mk"

.if ${OPSYS} == "NetBSD"
DEFS+=		-D_KERNTYPES
.endif
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
USE_SUN_AUDIO?=	YES
.else
USE_SUN_AUDIO?=	NO
.endif
DEFS+=		-DRomDir=\"${PREFIX:Q}/share/fmsx\"
.if ${USE_SUN_AUDIO} == "YES"
DEFS+=		-DSUN_AUDIO
.else
.  include "../../mk/oss.buildlink3.mk"

SUBST_CLASSES+=		devdsp
SUBST_STAGE.devdsp=	pre-build
SUBST_FILES.devdsp=	EMULib/SndUnix.c
SUBST_SED.devdsp=	-e 's|/dev/dsp|${DEVOSSSOUND}|g'

.endif
.if ${MACHINE_ENDIAN} == "big"
DEFS+=		-DMSB_FIRST
.elif ${MACHINE_ENDIAN} == "little"
DEFS+=		-DLSB_FIRST
.else
BROKEN=		"Unknown endian"
.endif

MAKE_ENV+=	DEFS=${DEFS:Q}

INSTALLATION_DIRS=	bin share/fmsx share/doc

# Makefile of fMSX doesn't have install target.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fMSX/Unix/fmsx ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fMSX/ROMs/*.ROM ${DESTDIR}${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/fMSX/ROMs/*.FNT ${DESTDIR}${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/fMSX/fMSX.html ${DESTDIR}${PREFIX}/share/doc

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
