# $NetBSD: Makefile,v 1.35 2005/06/24 06:43:43 jlam Exp $

DISTNAME=	pilotmgr-1.107p2
PKGNAME=	pilotmgr-1.107.2
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.moshpit.org/pilotmgr/
COMMENT=	Synchronize databases on any 3Com Palm device

DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Tk-[0-9]*:../../x11/p5-Tk
DEPENDS+=	p5-pilot-link-[0-9]*:../p5-pilot-link
DEPENDS+=	{p5-Data-Dumper-[0-9]*,perl>=5.6.1nb2}:../../lang/perl5

WRKSRC=			${WRKDIR}/${DISTNAME:C/-.*$//}
HAS_CONFIGURE=		YES
NO_BUILD=		YES

CONFIGURE_ARGS=		</dev/null
CONFIGURE_ENV+=		PERL="${LOCALBASE}/bin/perl" WRKDIR="${WRKDIR}"
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

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
