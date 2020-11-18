# $NetBSD: Makefile,v 1.1 2020/11/18 15:18:39 schmonz Exp $

DISTNAME=		ucspi-ipc-0.67
CATEGORIES=		net sysutils
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.superscript.com/ucspi-ipc/
COMMENT=		UCSPI local-domain client-server command-line tools

WRKSRC=			${WRKDIR}/host/superscript.com/net/${DISTNAME}
DJB_SLASHPACKAGE=	yes
DJB_RESTRICTED=		no

BUILD_DEFS+=		VARBASE

DJB_CONFIG_CMDS=	\
	${ECHO} ${VARBASE}/service/ipcexec > conf-ipcexec;	\
	${ECHO} it-base > it=d;

INSTALLATION_DIRS=	bin

.include "options.mk"

do-test:
	cd ${WRKSRC}; \
		./package/rts

do-install: do-install-ipcperl
	for f in ipccat ipcconnect ipcdo ipcrun; do \
	    ${INSTALL_SCRIPT} ${WRKSRC}/command/$$f ${DESTDIR}${PREFIX}/bin; \
	done
	for f in ipcclient ipccommand ipcconnect-io ipcexec ipcexec-config \
		ipcexecrules ipcexecrulescheck \
		ipcrules ipcrulescheck ipcserver; do \
	    ${INSTALL_PROGRAM} ${WRKSRC}/command/$$f ${DESTDIR}${PREFIX}/bin; \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
