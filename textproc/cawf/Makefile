# $NetBSD: Makefile,v 1.1.1.1 2005/01/20 17:59:12 tv Exp $
#

DISTNAME=		cawf
PKGNAME=		cawf-4.10
CATEGORIES=		textproc
MASTER_SITES=		http://www.tux.org/pub/sites/vic.cc.purdue.edu/
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_SUFX=		.zip

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.tux.org/pub/sites/vic.cc.purdue.edu/
COMMENT=		Simplistic nroff-like formatter in C, like "awf"

WRKSRC=			${WRKDIR}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_BUILDLINK3=		yes

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-DUNIX -DUSG -DSTDLIB -DCAWFLIB='\"${PREFIX}/share/cawf\"'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsfilt ${WRKSRC}/cawf ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/*.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/cawf
	${INSTALL_DATA} ${WRKSRC}/device.cf ${PREFIX}/share/cawf/
	${INSTALL_DATA} ${WRKSRC}/*.dev ${WRKSRC}/*.mac ${PREFIX}/share/cawf/
	${INSTALL_DATA} ${WRKSRC}/00diffs ${PREFIX}/share/cawf/DIFFS

.include "../../mk/bsd.pkg.mk"
