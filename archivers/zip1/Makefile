# $NetBSD: Makefile,v 1.1 1998/06/20 23:27:49 tv Exp $
#

DISTNAME=	zip1-1.1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.cdrom.com/pub/infozip/src/ \
		ftp://ftp.icce.rug.nl/infozip/src/
DISTFILES=	zip11.zip

MAINTAINER=	tv@netbsd.org

FETCH_DEPENDS=	unzip:../../archivers/unzip

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-qo

MAKEFILE=	makefile
MAKE_FLAGS=	CFLAGS="${CFLAGS} -DDIRENT" LFLAGS2="-lcompat"
ALL_TARGET=	zip

NO_WRKSUBDIR=	yes
PLIST_SRC=	${WRKSRC}/PLIST

.include "../../mk/bsd.prefs.mk"

.if defined(ZIP_ENCRYPTION)
DISTFILES+=	zcrypt10.zip
ALL_TARGET+=	zipcloak
RESTRICTED=	crypto
MIRROR_DISTFILE=no
.endif

do-install:
	@${CP} ${PKGDIR}/PLIST.pre ${PLIST_SRC}
	cd ${WRKSRC} && ${INSTALL_PROGRAM} zip ${PREFIX}/bin/zip1
	cd ${WRKSRC} && ${INSTALL_MAN} zip.1 ${PREFIX}/man/man1/zip1.1
.if defined(ZIP_ENCRYPTION)
	cd ${WRKSRC} && ${INSTALL_PROGRAM} zipcloak ${PREFIX}/bin/zipcloak1
	ln -fs zip1.1 ${PREFIX}/man/man1/zipcloak1.1
	@${ECHO} >>${PLIST_SRC} "bin/zipcloak1"
	@${ECHO} >>${PLIST_SRC} "man/man1/zipcloak1.1"
.endif

.include "../../mk/bsd.pkg.mk"
