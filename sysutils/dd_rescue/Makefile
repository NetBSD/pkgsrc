# $NetBSD: Makefile,v 1.3 2007/12/22 04:27:16 taca Exp $

DISTNAME=	dd_rescue-1.14
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://www.garloff.de/kurt/linux/ddrescue/
COMMENT=	dd(1)-like tool for rescuing data from media with errors

WRKSRC=		${WRKDIR}/dd_rescue

BUILD_TARGET=	dd_rescue

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}
PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/dd_rescue ${DESTDIR}${PREFIX:Q}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC:Q}/README.dd_rescue \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/README

.include "../../mk/bsd.pkg.mk"
