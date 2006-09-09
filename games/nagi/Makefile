# $NetBSD: Makefile,v 1.13 2006/09/09 02:42:00 obache Exp $
#

DISTNAME=		nagi_src_-_2002-11-14
PKGNAME=		nagi-20021114
PKGREVISION=		5
CATEGORIES=		games
MASTER_SITES=		http://www.agidev.com/dl_files/nagi/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.agidev.com/projects/nagi/
COMMENT=		Clone of Sierra's AGI

WRKSRC=		${WRKDIR}/src
USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.linux

NAGILIB=	${PREFIX}/lib/nagi

INSTALLATION_DIRS=	bin

post-build:
	${SED} "s|@PREFIX@|${PREFIX}|" <${FILESDIR}/nagi.sh >${WRKDIR}/nagi.sh

do-install:
	${INSTALL_DATA_DIR} ${NAGILIB}
	${INSTALL_PROGRAM} ${WRKDIR}/bin/nagi ${NAGILIB}
	${INSTALL_DATA} ${WRKDIR}/bin/*.nbf ${WRKDIR}/bin/*.ini ${NAGILIB}
	${INSTALL_SCRIPT} ${WRKDIR}/nagi.sh ${PREFIX}/bin/nagi

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
