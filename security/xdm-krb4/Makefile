# $NetBSD: Makefile,v 1.10 2001/08/09 19:29:46 wiz Exp $
#

DISTNAME=		xdm-krb4-3.3.6.2
CATEGORIES=		security x11
MASTER_SITES=		ftp://gutemine.geo.Uni-Koeln.DE/pub/xdm-krb4/

MAINTAINER=		wennmach@netbsd.org
COMMENT=		Kerberos IV and AFS aware xdm

DEPENDS+=               kth-krb4>=1.0.1:../../security/kth-krb4

USE_X11BASE=		yes
USE_IMAKE=		yes

.include "../../mk/bsd.prefs.mk"

post-patch:
	@${SED} -e 's|@PREFIX@|${LOCALBASE}|g'                                \
		< ${WRKSRC}/Imakefile.in                                      \
		> ${WRKSRC}/Imakefile

pre-install:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g'                                   \
		${FILESDIR}/xdm_krb4                                          \
		>${WRKDIR}/xdm_krb4   

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/rc.d
	${INSTALL_DATA}                                                       \
		${WRKDIR}/xdm_krb4                                            \
		${PREFIX}/etc/rc.d/xdm_krb4

.include "../../mk/bsd.pkg.mk"
