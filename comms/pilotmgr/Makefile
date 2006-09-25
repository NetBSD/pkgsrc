# $NetBSD: Makefile,v 1.41 2006/09/25 12:57:21 tron Exp $

DISTNAME=	pilotmgr-1.107p2
PKGNAME=	pilotmgr-1.107.2
PKGREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.moshpit.org/pilotmgr/
COMMENT=	Synchronize databases on any 3Com Palm device

DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Tk-[0-9]*:../../x11/p5-Tk
DEPENDS+=	p5-pilot-link-[0-9]*:../../comms/p5-pilot-link

WRKSRC=			${WRKDIR}/${DISTNAME:C/-.*$//}
HAS_CONFIGURE=		YES
NO_BUILD=		YES
USE_TOOLS+=		perl:run

CONFIGURE_ARGS+=	</dev/null
CONFIGURE_ENV+=		PERL="${LOCALBASE}/bin/perl" WRKDIR=${WRKDIR:Q}
CONFIGURE_SCRIPT=	./Setup

PM_PERL_DIR=	${PREFIX}/lib/${DISTNAME:C/-.*$//}
PM_DOC_DIR=	${PREFIX}/share/doc/${DISTNAME:C/-.*$//}

INSTALLATION_DIRS=	bin

post-extract:
	@${RM} -f ${WRKSRC}/SyncCM.pm
	@${CHMOD} +x ${WRKSRC}/Setup

pre-install:
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA_DIR} ${PM_PERL_DIR}
	${INSTALL_DATA_DIR} ${PM_DOC_DIR}
	for FILE in ${WRKSRC}/*.pm; do \
		${INSTALL_DATA} $$FILE ${PM_PERL_DIR}; \
	done
	${CHMOD} ${BINMODE} ${PM_PERL_DIR}/PilotMgr.pm
	${LN} -fs ${PM_PERL_DIR}/PilotMgr.pm ${PREFIX}/bin/PilotManager
	cd ${WRKSRC} && \
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

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
