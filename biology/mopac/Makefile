# $NetBSD: Makefile,v 1.7 2012/09/11 20:32:13 asau Exp $
#

DISTNAME=		mopac7
PKGNAME=		mopac-7.0
PKGREVISION=		1
CATEGORIES=		biology math
MASTER_SITES=		http://server.ccl.net/cca/software/LINUX/mopac7/
EXTRACT_SUFX=		.tar.Z
DISTFILES=		${DEFAULT_DISTFILES} mopac7-man.tar.gz

PATCH_SITES=		${MASTER_SITES:=old-version-95.06.21/}
PATCHFILES=		mopac7-linux.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://server.ccl.net/cca/software/LINUX/mopac7/index.shtml
COMMENT=		Molecular energy calculation program

WRKSRC=			${WRKDIR}/mopac7
BUILD_TARGET=		MOPAC7
USE_TOOLS+=		gmake pax
USE_LANGUAGES=		fortran77
PKG_FC=			f2c-f77

INSTALLATION_DIRS=	bin share/mopac7/sample

pre-build:
	cp ${WRKSRC}/esp.rof ${WRKSRC}/esp.f
	rm -f ${WRKSRC}/Makefile
	cp ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mopac ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/MOPAC7 ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && pax -wr test_* \
	  ${DESTDIR}${PREFIX}/share/mopac7/sample
	cd ${WRKDIR} && pax -wr mopac7-man ${DESTDIR}${PREFIX}/share/mopac7

# "g77" can not be used for external function

.include "../../devel/libf2c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
