# $NetBSD: Makefile,v 1.2 2004/01/24 13:30:56 grant Exp $
#

DISTNAME=		nagi_src_-_2002-11-14
PKGNAME=		nagi-20021114
CATEGORIES=		games
MASTER_SITES=		http://www.agidev.com/dl_files/nagi/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.agidev.com/projects/nagi/
COMMENT=		Clone of Sierra's AGI

WRKSRC=		${WRKDIR}/src
USE_BUILDLINK2=	yes
USE_GNU_TOOLS+=	make
MAKEFILE=	Makefile.linux

NAGILIB=	${PREFIX}/lib/nagi

post-build:
	${SED} "s|@PREFIX@|${PREFIX}|" <${FILESDIR}/nagi.sh >${WRKDIR}/nagi.sh

do-install:
	${INSTALL_DATA_DIR} ${NAGILIB}
	${INSTALL_PROGRAM} ${WRKDIR}/bin/nagi ${NAGILIB}
	${INSTALL_DATA} ${WRKDIR}/bin/*.nbf ${WRKDIR}/bin/*.ini ${NAGILIB}
	${INSTALL_SCRIPT} ${WRKDIR}/nagi.sh ${PREFIX}/bin/nagi

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
