# $NetBSD: Makefile,v 1.8 2013/04/06 03:45:24 rodent Exp $

DISTNAME=	dd_rescue-1.23
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE:Q}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.garloff.de/kurt/linux/ddrescue/
COMMENT=	Tool like dd(1) for rescuing data from media with errors
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/dd_rescue

BUILD_TARGET=	dd_rescue

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dd_rescue ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README.dd_rescue \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/README

.include "../../mk/bsd.pkg.mk"
