# $NetBSD: Makefile,v 1.1.1.1 1999/05/24 18:09:46 tron Exp $

DISTNAME=	pilotmgr-1.0.7
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.moshpit.org/pilotmgr/

DEPENDS+=	p5-MD5-1.7:../../security/p5-MD5
DEPENDS+=	p5-Tk-402.002:../../x11/p5-Tk
DEPENDS+=	p5-pilot-link-0.9.3:../p5-pilot-link

USE_X11=	yes
HAS_CONFIGURE=	yes
NO_BUILD=	yes

CONFIGURE_ARGS=		</dev/null
CONFIGURE_SCRIPT=	Setup
WRKSRC=			${WRKDIR}/${DISTNAME:C/-.*$//}

SITE_PERL_DIR=	${PREFIX}/lib/perl5/site_perl/${MACHINE_ARCH}-${LOWER_OPSYS}
PM_PERL_DIR=	${SITE_PERL_DIR}/${DISTNAME:C/-.*$//}
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

.include <../../mk/bsd.pkg.mk>
