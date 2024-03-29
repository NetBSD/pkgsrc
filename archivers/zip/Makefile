# $NetBSD: Makefile,v 1.66 2023/08/28 13:55:59 wiz Exp $

DISTNAME=	zip30
PKGNAME=	zip-3.0
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.info-zip.org/pub/infozip/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.info-zip.org/Zip.html
COMMENT=	Create/update ZIP files compatible with pkzip
LICENSE=	info-zip

MAKE_FILE=	unix/Makefile

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=	LOCAL_ZIP=${CFLAGS:Q}
MAKE_FLAGS+=	LFLAGS1=${_STRIPFLAG_CC:Q}
MAKE_FLAGS+=	-DUNICODE_SUPPORT

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mgcc) || !empty(PKGSRC_COMPILER:Mclang)
BUILD_TARGET=	generic_gcc
.else
BUILD_TARGET=	generic
CFLAGS+=	-O
.endif

.if ${MACHINE_ARCH} == "i386" && ${PKGSRC_MKPIE:tl} != "no"
# Text relocations
MAKE_FLAGS+=	DISABLE_ASM=YES
.endif

.if !empty(PKGSRC_COMPILER:Msunpro)
MAKE_FLAGS+=	DISABLE_ASM=YES
.endif

.if ${OPSYS} == "Linux"
CFLAGS+=	-DHAVE_DIRENT_H
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} zip zipnote zipsplit zipcloak ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/man && \
	    ${INSTALL_MAN} zip.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${LN} -f -s zip.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/zipcloak.1
	${LN} -f -s zip.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/zipnote.1
	${LN} -f -s zip.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/zipsplit.1

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
