# $NetBSD: Makefile,v 1.56 2019/08/11 13:18:09 wiz Exp $

DISTNAME=	pilotmgr-1.109
PKGREVISION=	8
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pilotmanager/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pilotmanager.sourceforge.net/
COMMENT=	Synchronize databases on any 3Com Palm device

#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
DEPENDS+=	p5-Tk-[0-9]*:../../x11/p5-Tk
DEPENDS+=	p5-pilot-link-[0-9]*:../../comms/p5-pilot-link

HAS_CONFIGURE=		YES
NO_BUILD=		YES
USE_TOOLS+=		perl:run

CONFIGURE_ENV+=		PERL=${LOCALBASE}/bin/perl
CONFIGURE_ENV+=		WRKDIR=${WRKDIR}
CONFIG_SHELL=		perl
CONFIGURE_SCRIPT=	Setup.pl
CONFIGURE_ARGS+=	</dev/null

PM_PERL_DIR=	${PREFIX}/lib/${DISTNAME:C/-.*$//}
PM_DOC_DIR=	${PREFIX}/share/doc/${DISTNAME:C/-.*$//}

INSTALLATION_DIRS=	bin

post-extract:
	${RM} -f ${WRKSRC}/SyncCM.pm

pre-install:
	${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PM_PERL_DIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PM_DOC_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/PilotManager ${DESTDIR}${PM_PERL_DIR}
	for FILE in ${WRKSRC}/*.pm; do \
		${INSTALL_DATA} $$FILE ${DESTDIR}${PM_PERL_DIR}; \
	done
	${LN} -fs ${PM_PERL_DIR}/PilotManager ${DESTDIR}${PREFIX}/bin/PilotManager
	cd ${WRKSRC} && \
		for DIR in lib/*; do \
			${INSTALL_DATA_DIR} ${DESTDIR}${PM_PERL_DIR}/$$DIR; \
			for FILE in $$DIR/*; do \
				${INSTALL_DATA} $$FILE ${DESTDIR}${PM_PERL_DIR}/$$DIR; \
			done; \
		done
	for FILE in ${WRKSRC}/docs/*; do \
		${INSTALL_DATA} $$FILE ${DESTDIR}${PM_DOC_DIR}; \
	done
	${LN} -fs ${PM_DOC_DIR} ${DESTDIR}${PM_PERL_DIR}/docs

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
