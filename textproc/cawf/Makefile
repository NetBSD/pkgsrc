# $NetBSD: Makefile,v 1.14 2012/10/25 06:55:44 asau Exp $
#
# Possible TODOs:
# - set CH based on manual page section number, and real OS name
# - add -mdoc implementation and/or translator
# - use system getopt(3)?
# - use system regex support?

DISTNAME=		cawf
PKGNAME=		cawf-4.10
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		http://www.tux.org/pub/sites/vic.cc.purdue.edu/
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://vic.cc.purdue.edu/pub/cawf.README
COMMENT=		Simplistic nroff-like formatter in C, like "awf"

WRKSRC=			${WRKDIR}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-DUNIX -DUSG -DSTDLIB -DCAWFLIB="\"${PREFIX}/share/cawf\""

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/cawf

post-extract:
	${RM} -f ${WRKSRC}/*.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsfilt ${WRKSRC}/cawf ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/common ${DESTDIR}${PREFIX}/share/cawf/
	${INSTALL_DATA} ${WRKSRC}/device.cf ${DESTDIR}${PREFIX}/share/cawf/
	${INSTALL_DATA} ${WRKSRC}/*.dev ${WRKSRC}/*.mac ${DESTDIR}${PREFIX}/share/cawf/
	${INSTALL_DATA} ${WRKSRC}/00diffs ${DESTDIR}${PREFIX}/share/cawf/DIFFS

.include "../../mk/bsd.pkg.mk"
