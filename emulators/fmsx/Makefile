# $NetBSD: Makefile,v 1.36 2020/03/08 16:49:26 wiz Exp $

DISTNAME=	fMSX53
PKGNAME=	fmsx-5.3
PKGREVISION=	3
CATEGORIES=	emulators x11
MASTER_SITES=	http://fms.komkon.org/fMSX/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fms.komkon.org/fMSX/
COMMENT=	MSX (Z80-based computer) emulator

RESTRICTED=		The binary based on modified source code is not redistributable
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

WRKSRC=	${WRKDIR}

USE_TOOLS+=	gmake

BUILD_DIRS=	fMSX/Unix

.include "../../mk/bsd.prefs.mk"
.include "../../mk/endian.mk"

.if ${OPSYS} == "NetBSD"
DEFS+=		-D_KERNTYPES
.endif

.if ${MACHINE_ENDIAN} == "big"
DEFS+=		-DMSB_FIRST
.elif ${MACHINE_ENDIAN} == "little"
DEFS+=		-DLSB_FIRST
.else
BROKEN=		"Unknown endian"
.endif

MAKE_ENV+=	DEFS=${DEFS:Q}

INSTALLATION_DIRS=	bin share/doc

# Makefile of fMSX doesn't have install target.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fMSX/Unix/fmsx ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fMSX/fMSX.html ${DESTDIR}${PREFIX}/share/doc

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
