# $NetBSD: Makefile,v 1.1.1.1 2001/08/06 09:46:47 rh Exp $
#

DISTNAME=	pxe-1.2
CATEGORIES=	net sysutils
MASTER_SITES=	http://www.kano.org.uk/projects/pxe/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kano.org.uk/projects/pxe/
COMMENT=	Preboot eXecution Environment (PXE) daemon

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-log=/var/log/pxe.log
CONFIGURE_ARGS+=--with-config=${PREFIX}/etc/pxe.conf

post-configure:
	${SED} -e 's|@@PREFIX@@|${PREFIX}|g' < ${FILESDIR}/pxe > ${WRKDIR}/pxe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pxe ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pxe
	${INSTALL_DATA} ${WRKSRC}/pxe.conf ${PREFIX}/share/examples/pxe
	${INSTALL_SCRIPT_DIR} ${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKDIR}/pxe ${PREFIX}/etc/rc.d

.include "../../mk/bsd.pkg.mk"
