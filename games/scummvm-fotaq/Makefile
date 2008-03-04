# $NetBSD: Makefile,v 1.6 2008/03/04 06:59:06 jlam Exp $
#

DISTNAME=		FOTAQ_Floppy
PKGNAME=		scummvm-fotaq-0
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scummvm/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scummvm.org/
COMMENT=		Flight Of The Amazon Queen

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/FOTAQ_Floppy

FOTAQDIR=	${PREFIX}/share/games/fotaq

INSTALLATION_DIRS=	bin

do-build:
	${SED} "s|@FOTAQDIR@|${FOTAQDIR}|" <${FILESDIR}/fotaq.sh \
		>${WRKDIR}/fotaq.sh

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FOTAQDIR}
	${INSTALL_DATA} ${WRKSRC}/queen.1 ${DESTDIR}${FOTAQDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/fotaq.sh ${DESTDIR}${PREFIX}/bin/fotaq

.include "../../mk/bsd.pkg.mk"
