# $NetBSD: Makefile,v 1.2 2000/05/15 11:26:20 wulf Exp $
#

DISTNAME=	dpbox-60000
PKGNAME=	dpbox-6.00.00
WRKSRC=		${WRKDIR}/dpbox-6.00.00/source
CATEGORIES=	ham
MASTER_SITES=	http://userpage.fu-berlin.de/~jschurig/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://userpage.fu-berlin.de/~jschurig/

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
