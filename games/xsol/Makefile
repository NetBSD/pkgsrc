# $NetBSD: Makefile,v 1.1 2022/01/17 13:23:17 nia Exp $

DISTNAME=	xsol_0.31.orig
PKGNAME=	${DISTNAME:S/_/-/g:S/.orig$//g}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xsol/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.debian.org/sid/xsol
COMMENT=	Solitaire game for the X Window System
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/g}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	${PKGMANDIR}/man6

pre-build:
	${CP} -f ${FILESDIR}/Makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsol \
	    ${DESTDIR}${PREFIX}/bin/xsol
	${INSTALL_DATA} ${FILESDIR}/xsol.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/xsol.desktop
	${INSTALL_DATA} ${FILESDIR}/xsol.6 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/xsol.6
	${INSTALL_DATA} ${FILESDIR}/xsol.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps/xsol.png

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
