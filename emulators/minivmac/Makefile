# $NetBSD: Makefile,v 1.18 2009/09/02 08:34:13 wiz Exp $

DISTNAME=	minivmac-0.1.7.src
PKGNAME=	minivmac-0.1.7
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=minivmac/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://minivmac.sourceforge.net/
COMMENT=	Miniature Macintosh emulator

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/minivmac

SCRIPTS_ENV+=	CC="${CC}"

DOCDIR=		${PREFIX}/share/doc/html/minivmac

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}/tool/bash; ${SETENV} ${SCRIPTS_ENV} ${SH} build

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/drv/minivmac ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DESTDIR}${DOCDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
