# $NetBSD: Makefile,v 1.1.1.1 2000/05/15 10:54:44 wulf Exp $
#

DISTNAME=	dpbox-60000
PKGNAME=	dpbox-6.00.00
WRKSRC=		${WRKDIR}/dpbox-6.00.00/source
CATEGORIES=	ham
MASTER_SITES=	ftp://ftp.ping.net.au/pub/unix/ham/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://userpgages.fu-berlin.de/

LICENSE=        no-commercial-use

USE_GMAKE=	yes
MAKEFILE=	Makefile.netbsd

.include "../../mk/bsd.prefs.mk"

DPBOX_CONF_DIR=	${PREFIX}/share/dpbox/conf
DPBOX_SPOOL_DIR=/var/spool/dpbox
DEINSTALL_FILE= ${WRKDIR}/DEINSTALL

post-build:
	@cd ${PKGDIR}; \
	${SED} -e 's#@DPBOX_CONF_DIR@#${DPBOX_CONF_DIR}#g' \
	       -e 's#@DPBOX_SPOOL_DIR@#${DPBOX_SPOOL_DIR}#g' \
	       < DEINSTALL > ${WRKDIR}/DEINSTALL; \
	${SED} -e 's#@prefix@#${PREFIX}#g' \
	       < ${FILESDIR}/dpbox.ini > ${WRKDIR}/dpbox-6.00.00/dpbox.ini

.include "../../mk/bsd.pkg.mk"
