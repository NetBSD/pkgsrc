# $NetBSD: Makefile,v 1.25 2004/04/25 23:16:22 tv Exp $
#

DISTNAME=	zip1-1.1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.cdrom.com/pub/infozip/src/ \
		ftp://ftp.icce.rug.nl/infozip/src/
DISTFILES=	zip11.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.info-zip.org/pub/infozip/
COMMENT=	Create/update ZIP files compatible with pkzip version 1

RESTRICTED=	"Do not modify.  Do not sell for profit."
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

NOT_FOR_PLATFORM+= Interix-*-* # needs porting

WRKSRC=		${WRKDIR}
MAKEFILE=	makefile
MAKE_FLAGS=	CFLAGS="${CFLAGS} -DDIRENT" LFLAGS2="-lcompat"
ALL_TARGET=	zip

USE_BUILDLINK3=	yes
PLIST_SRC=	${WRKSRC}/PLIST

BUILD_DEFS+=	ZIP_ENCRYPTION

.include "../../mk/bsd.prefs.mk"

.if defined(ZIP_ENCRYPTION)
DISTFILES+=	zcrypt10.zip
ALL_TARGET+=	zipcloak
CRYPTO=		yes
.endif

do-install:
	@${CP} ${PKGDIR}/PLIST.pre ${PLIST_SRC}
	cd ${WRKSRC} && ${INSTALL_PROGRAM} zip ${PREFIX}/bin/zip1
	cd ${WRKSRC} && ${INSTALL_MAN} zip.1 ${PREFIX}/man/man1/zip1.1
.if defined(ZIP_ENCRYPTION)
	cd ${WRKSRC} && ${INSTALL_PROGRAM} zipcloak ${PREFIX}/bin/zipcloak1
	${LN} -fs zip1.1 ${PREFIX}/man/man1/zipcloak1.1
	@${ECHO} >>${PLIST_SRC} "bin/zipcloak1"
	@${ECHO} >>${PLIST_SRC} "man/man1/zipcloak1.1"
.endif

.include "../../mk/bsd.pkg.mk"
