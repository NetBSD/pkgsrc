# $NetBSD: Makefile,v 1.4 2001/01/26 05:21:48 hubertf Exp $
#

DISTNAME=		xdm-krb4-3.3.6.2
CATEGORIES=		security x11
MASTER_SITES=		ftp://gutemine.geo.Uni-Koeln.DE/pub/xdm-krb4/

MAINTAINER=		wennmach@netbsd.org
#HOMEPAGE=

DEPENDS+=               kth-krb4-1.0.1:../../security/kth-krb4

USE_X11BASE=		yes
USE_IMAKE=		yes

MESSAGE_FILE=		${WRKDIR}/MESSAGE

.include "../../mk/bsd.prefs.mk"

post-patch:
	@${SED} -e 's|@PREFIX@|${LOCALBASE}|g'                                \
		< ${WRKSRC}/Imakefile.in                                      \
		> ${WRKSRC}/Imakefile

pre-install:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g'                                   \
		<${PKGDIR}/MESSAGE                                            \
		>${MESSAGE_FILE}
	@${SED} -e 's|@PREFIX@|${PREFIX}|g'                                   \
		<${FILESDIR}/xdm-krb4.sh                                      \
		>${WRKDIR}/xdm-krb4.sh

post-install:
	-${MKDIR} ${PREFIX}/etc/rc.d
	${INSTALL} -c -o root -g wheel -m 444                                 \
		${WRKDIR}/xdm-krb4.sh                                         \
		${PREFIX}/etc/rc.d/xdm-krb4

.include "../../mk/bsd.pkg.mk"
