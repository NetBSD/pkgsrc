# $NetBSD: Makefile,v 1.8 2001/02/25 04:18:15 hubertf Exp $
#

DISTNAME=		xdm-krb4-3.3.6.2
CATEGORIES=		security x11
MASTER_SITES=		ftp://gutemine.geo.Uni-Koeln.DE/pub/xdm-krb4/

MAINTAINER=		wennmach@netbsd.org
COMMENT=		Kerberos IV and AFS aware xdm

DEPENDS+=               kth-krb4-1.0.1:../../security/kth-krb4

USE_X11BASE=		yes
USE_IMAKE=		yes

.include "../../mk/bsd.prefs.mk"

post-patch:
	@${SED} -e 's|@PREFIX@|${LOCALBASE}|g'                                \
		< ${WRKSRC}/Imakefile.in                                      \
		> ${WRKSRC}/Imakefile

pre-install:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g'                                   \
		<${FILESDIR}/xdm-krb4.sh                                      \
		>${WRKDIR}/xdm-krb4.sh

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/rc.d
	${INSTALL_DATA}                                                       \
		${WRKDIR}/xdm-krb4.sh                                         \
		${PREFIX}/etc/rc.d/xdm-krb4

.include "../../mk/bsd.pkg.mk"
