# $NetBSD: Makefile,v 1.3 2004/04/21 04:56:25 snj Exp $
#

DISTNAME=		qmail-qfilter-1.5
CATEGORIES=		mail
MASTER_SITES=		http://untroubled.org/qmail-qfilter/

MAINTAINER=		zuntum@NetBSD.org
HOMEPAGE=		http://untroubled.org/qmail-qfilter/
COMMENT=		qmail-queue multi-filter front end

USE_BUILDLINK3=		yes

REPLACE_PERL=		samples/block-long-dates			\
			samples/deny-filetypes				\
			samples/rename-filetypes

post-patch:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qmail-qfilter ${PREFIX}/bin

	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/qmail-qfilter

	${INSTALL_SCRIPT} ${WRKSRC}/samples/block-long-dates		\
		${PREFIX}/share/examples/qmail-qfilter
	${INSTALL_SCRIPT} ${WRKSRC}/samples/deny-filetypes		\
		${PREFIX}/share/examples/qmail-qfilter
	${INSTALL_SCRIPT} ${WRKSRC}/samples/rename-filetypes		\
		${PREFIX}/share/examples/qmail-qfilter

.include "../../mk/bsd.pkg.mk"
