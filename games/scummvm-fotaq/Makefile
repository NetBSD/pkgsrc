# $NetBSD: Makefile,v 1.1.1.1 2004/05/05 08:25:44 drochner Exp $
#

DISTNAME=		FOTAQ_Floppy
PKGNAME=		scummvm-fotaq-0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scummvm/}
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.scummvm.org/
COMMENT=		Flight Of The Amazon Queen

WRKSRC=			${WRKDIR}/FOTAQ_Floppy
NO_BUILDLINK=		yes

FOTAQDIR=	${PREFIX}/share/games/fotaq

do-build:
	${SED} "s|@FOTAQDIR@|${FOTAQDIR}|" <${FILESDIR}/fotaq.sh \
		>${WRKDIR}/fotaq.sh

do-install:
	${INSTALL_DATA_DIR} ${FOTAQDIR}
	${INSTALL_DATA} ${WRKSRC}/queen.1 ${FOTAQDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/fotaq.sh ${PREFIX}/bin/fotaq

.include "../../mk/bsd.pkg.mk"
