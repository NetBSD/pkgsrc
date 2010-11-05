# $NetBSD: Makefile,v 1.5 2010/11/05 08:23:27 ghen Exp $

DISTNAME=	dd_rescue-1.14
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE:Q}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.garloff.de/kurt/linux/ddrescue/
COMMENT=	dd(1)-like tool for rescuing data from media with errors
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/dd_rescue

BUILD_TARGET=	dd_rescue

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}
PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dd_rescue ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README.dd_rescue \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/README

.include "../../mk/bsd.pkg.mk"
