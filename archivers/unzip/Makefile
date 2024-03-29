# $NetBSD: Makefile,v 1.97 2023/08/28 13:55:59 wiz Exp $

DISTNAME=	unzip60
PKGNAME=	unzip-6.0
PKGREVISION=	9
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.info-zip.org/pub/infozip/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.info-zip.org/UnZip.html
COMMENT=	List, test and extract compressed files in a ZIP archive
LICENSE=	info-zip

REPLACE_SH=	unix/zipgrep

USE_TOOLS+=	gmake

CONFLICTS=	fcrackzip<1.0nb1

.include "../../mk/bsd.prefs.mk"

MAKE_FILE=	unix/Makefile
BUILD_TARGET=	generic_zlib unzipsfx

.if ${OPSYS:M*BSD} != "" || ${OPSYS} == "Darwin"
CPPFLAGS+=	-DBSD
.endif
.if (${OPSYS} == "SunOS" || \
     ${OPSYS} == "OSF1"  || \
     ${OPSYS} == "AIX"  || \
     ${OPSYS} == "OpenBSD"  || \
     ${OPSYS} == "Cygwin"  || \
    (${OPSYS} == "Darwin" && !empty(OS_VERSION:M[01234678].*))) || \
     ${OS_VARIANT} == "SCOOSR5" || \
     ${OPSYS} == "Linux"  || \
     ${OPSYS} == "Bitrig"
CPPFLAGS+=	-DNO_LCHMOD
.endif
CPPFLAGS+=	-DUNIX -Dunix -DUSE_UNSHRINK -I.
.if empty(MACHINE_PLATFORM:MSunOS-*-sparc)
CPPFLAGS+=	-DLARGE_FILE_SUPPORT
.endif

MAKE_FLAGS+=	CF=${CPPFLAGS:Q}\ ${CFLAGS:Q}
MAKE_FLAGS+=	LF2=${_STRIPFLAG_CC:Q}\ ${LDFLAGS:Q}\ -lz

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/unzip

TEST_TARGET=	check

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unzip funzip unzipsfx ${DESTDIR}${PREFIX}/bin
	${LN} -sf unzip ${DESTDIR}${PREFIX}/bin/zipinfo
	cd ${WRKSRC}/unix && ${INSTALL_SCRIPT} zipgrep ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/man && ${INSTALL_MAN} funzip.1 unzip.1 unzipsfx.1 \
		zipgrep.1 zipinfo.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC} && ${INSTALL_DATA} BUGS LICENSE README WHERE \
		${DESTDIR}${PREFIX}/share/doc/unzip
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING.OLD \
		${DESTDIR}${PREFIX}/share/doc/unzip

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
