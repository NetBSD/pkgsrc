# $NetBSD: Makefile,v 1.17 2001/11/28 05:20:42 jlam Exp $

DISTNAME=	pilotmgr-1.107p2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.moshpit.org/pilotmgr/
COMMENT=	synchronize databases on any 3Com Palm device

DEPENDS+=	{p5-Data-Dumper-[0-9]*,perl>=5.6.1nb2}:../../lang/perl5
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Tk-[0-9]*:../../x11/p5-Tk
DEPENDS+=	p5-pilot-link-[0-9]*:../p5-pilot-link

USE_BUILDLINK_ONLY=	YES
HAS_CONFIGURE=		YES
NO_BUILD=		YES

CONFIGURE_ARGS=		</dev/null
CONFIGURE_SCRIPT=	./Setup
WRKSRC=			${WRKDIR}/${DISTNAME:C/-.*$//}

PM_PERL_DIR=	${PREFIX}/lib/${DISTNAME:C/-.*$//}
PM_DOC_DIR=	${PREFIX}/share/doc/${DISTNAME:C/-.*$//}

post-extract:
		@${RM} -f ${WRKSRC}/SyncCM.pm
		@${CHMOD} +x ${WRKSRC}/Setup

pre-install:
		@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

do-install:
		${INSTALL_DATA_DIR} ${PM_PERL_DIR} ${PM_DOC_DIR}
		for FILE in ${WRKSRC}/*.pm; do \
		  ${INSTALL_DATA} $$FILE ${PM_PERL_DIR}; \
		done
		${CHMOD} ${BINMODE} ${PM_PERL_DIR}/PilotMgr.pm
		${LN} -fs ${PM_PERL_DIR}/PilotMgr.pm ${PREFIX}/bin/PilotManager
		cd ${WRKSRC}; \
		for DIR in lib/*; do \
		  ${INSTALL_DATA_DIR} ${PM_PERL_DIR}/$$DIR; \
		  for FILE in $$DIR/*; do \
		    ${INSTALL_DATA} $$FILE ${PM_PERL_DIR}/$$DIR; \
		  done; \
		done
		for FILE in ${WRKSRC}/docs/*; do \
		  ${INSTALL_DATA} $$FILE ${PM_DOC_DIR}; \
		done
		${LN} -fs ${PM_DOC_DIR} ${PM_PERL_DIR}/docs

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
