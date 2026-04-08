# $NetBSD: Makefile,v 1.2 2026/04/08 16:10:20 sborrill Exp $
# Version is in Makefile.common shared with net/vnstati
# PKGREVISION should be bumped here

PKGREVISION=	1

PKGNAME=	${DISTNAME:S/-/i-/}

PATCHDIR=	../../net/vnstat/patches
PKGDIR=		../../net/vnstat
PLIST_SRC=	PLIST
DESCR_SRC=	../../net/vnstat/DESCR DESCR

CONFLICTS+=		vnstat<2.13
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

DEPENDS+=	vnstat>=2.13:../../net/vnstat
BUILD_TARGET=	vnstati

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vnstati			\
	    ${DESTDIR}${PREFIX}/bin/vnstati;			\
	${INSTALL_MAN} ${WRKSRC}/man/vnstati.1 			\
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vnstati.1

.include "../../net/vnstat/Makefile.common"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
