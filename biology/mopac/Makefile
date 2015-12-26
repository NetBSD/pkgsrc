# $NetBSD: Makefile,v 1.9 2015/12/26 22:36:07 dholland Exp $
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
USE_LANGUAGES=		c fortran77

INSTALLATION_DIRS=	bin share/mopac7/sample

# XXX  This package builds only with f2c, not g95.
# XXX  There does not appear to be any way to specify this other
# XXX  than by abusively setting PKGSRC_FORTRAN.
PKGSRC_FORTRAN=		f2c

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

.include "../../devel/libf2c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
