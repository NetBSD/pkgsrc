# $NetBSD: Makefile,v 1.10 2000/03/27 08:54:55 tron Exp $

DISTNAME=	pilotmgr-1.107p2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.moshpit.org/pilotmgr/

DEPENDS+=	p5-Data-Dumper-*:../../devel/p5-Data-Dumper
DEPENDS+=	p5-Digest-MD5-*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Tk-*:../../x11/p5-Tk
DEPENDS+=	p5-pilot-link-*:../p5-pilot-link

USE_X11=	yes
HAS_CONFIGURE=	yes
NO_BUILD=	yes

CONFIGURE_ARGS=		</dev/null
CONFIGURE_SCRIPT=	./Setup
WRKSRC=			${WRKDIR}/${DISTNAME:C/-.*$//}

PM_PERL_DIR=	${PREFIX}/lib/${DISTNAME:C/-.*$//}
PM_DOC_DIR=	${PREFIX}/share/doc/${DISTNAME:C/-.*$//}

post-extract:
		@${RM} -f ${WRKSRC}/SyncCM.pm
		@${CHMOD} +x ${WRKSRC}/Setup

do-install:
		${MKDIR} ${PM_PERL_DIR} ${PM_DOC_DIR}
		for FILE in ${WRKSRC}/*.pm; do \
		  ${INSTALL_DATA} $$FILE ${PM_PERL_DIR}; \
		done
		${CHMOD} ${BINMODE} ${PM_PERL_DIR}/PilotMgr.pm
		${LN} -fs ${PM_PERL_DIR}/PilotMgr.pm ${PREFIX}/bin/PilotManager
		cd ${WRKSRC}; \
		for DIR in lib/*; do \
		  ${MKDIR} ${PM_PERL_DIR}/$$DIR; \
		  for FILE in $$DIR/*; do \
		    ${INSTALL_DATA} $$FILE ${PM_PERL_DIR}/$$DIR; \
		  done; \
		done
		for FILE in ${WRKSRC}/docs/*; do \
		  ${INSTALL_DATA} $$FILE ${PM_DOC_DIR}; \
		done
		${LN} -fs ${PM_DOC_DIR} ${PM_PERL_DIR}/docs

.include "../../mk/bsd.pkg.mk"
