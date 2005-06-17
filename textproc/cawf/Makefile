# $NetBSD: Makefile,v 1.7 2005/06/17 03:50:36 jlam Exp $
#
# Possible TODOs:
# - set CH based on manual page section number, and real OS name
# - add -mdoc implementation and/or translator
# - use system getopt(3)?
# - use system regex support?

DISTNAME=		cawf
PKGNAME=		cawf-4.10
CATEGORIES=		textproc
MASTER_SITES=		ftp://vic.cc.purdue.edu/pub/ \
			http://www.tux.org/pub/sites/vic.cc.purdue.edu/
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_SUFX=		.zip

MAINTAINER=		tv@duh.org
HOMEPAGE=		ftp://vic.cc.purdue.edu/pub/cawf.README
COMMENT=		Simplistic nroff-like formatter in C, like "awf"

WRKSRC=			${WRKDIR}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-DUNIX -DUSG -DSTDLIB -DCAWFLIB="\"${PREFIX}/share/cawf\""

INSTALLATION_DIRS+=	bin man/man1

post-extract:
	${RM} -f ${WRKSRC}/*.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsfilt ${WRKSRC}/cawf ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/*.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/cawf
	${INSTALL_DATA} ${WRKSRC}/common ${PREFIX}/share/cawf/
	${INSTALL_DATA} ${WRKSRC}/device.cf ${PREFIX}/share/cawf/
	${INSTALL_DATA} ${WRKSRC}/*.dev ${WRKSRC}/*.mac ${PREFIX}/share/cawf/
	${INSTALL_DATA} ${WRKSRC}/00diffs ${PREFIX}/share/cawf/DIFFS

.include "../../mk/bsd.pkg.mk"
