# $NetBSD: Makefile,v 1.13 2006/05/27 21:32:30 agc Exp $

DISTNAME=	netbsd-iscsi-20060527
CATEGORIES=	devel
MASTER_SITES=	http://www.alistaircrooks.co.uk/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	NetBSD's iSCSI target (per iSCSI RFC 3720)

WRKSRC=		${WRKDIR}/${DISTNAME}/src

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/iscsi-target ${PREFIX}/sbin/iscsi-target
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/iscsi-harness ${PREFIX}/sbin/iscsi-harness
	${INSTALL_DATA_DIR} ${PREFIX}/share/iscsi
	${INSTALL_DATA} ${WRKSRC}/../doc/FAQ ${PREFIX}/share/iscsi/FAQ
	${INSTALL_MAN} ${WRKSRC}/iscsi-target.8 ${PREFIX}/man/man8/iscsi-target.8
	${INSTALL_MAN} ${WRKSRC}/targets.5 ${PREFIX}/man/man5/targets.5

.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
