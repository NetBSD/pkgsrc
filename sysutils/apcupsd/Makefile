# $NetBSD: Makefile,v 1.1.1.1 2000/01/21 19:15:59 bouyer Exp $
#

DISTNAME=	apcupsd-3.5.8.src
PKGNAME=	apcupsd-3.5.8
CATEGORIES=	sysutils
MASTER_SITES=	ftp://sunsite.unc.edu/pub/linux/system/ups/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.brisse.dk/site/apcupsd/

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apcupsd-netbsd ${PREFIX}/sbin/apcupsd
	${INSTALL_PROGRAM} ${WRKSRC}/apcaccess-netbsd ${PREFIX}/bin/apcaccess
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' ${WRKSRC}/installs/powersc > \
		${WRKDIR}/powersc
	${INSTALL_SCRIPT} ${WRKDIR}/powersc ${PREFIX}/sbin/
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' ${WRKSRC}/installs/apcupsd.conf > \
		${WRKDIR}/apcupsd.conf.sample
	${INSTALL_DATA} ${WRKDIR}/apcupsd.conf.sample ${PREFIX}/etc/
	@${MKDIR} ${PREFIX}/share/doc/apcupsd
	${INSTALL_DATA} ${WRKSRC}/readmes/README* \
		${WRKSRC}/readmes/minicom.apcupsd ${PREFIX}/share/doc/apcupsd/
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' ${WRKSRC}/docs/apcupsd.man8 > \
		${WRKDIR}/apcupsd.8
	${INSTALL_MAN} ${WRKDIR}/apcupsd.8 ${PREFIX}/man/man8/
.include "../../mk/bsd.pkg.mk"
