# $NetBSD: Makefile,v 1.6 1999/07/29 19:06:05 fredb Exp $
#

DISTNAME=	ntp-4.0.95
CATEGORIES=	net
MASTER_SITES=	http://www.eecis.udel.edu/~ntp/ntp_spool/testing/ \
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ \
		ftp://ftp.udel.edu/pub/ntp/testing/ \
		ftp://ftp.udel.edu/pub/ntp/ntp4/

MAINTAINER=	fb@enteract.com
HOMEPAGE=	http://www.ntp.org/

GNU_CONFIGURE=	YES

DOCDIR=		${PREFIX}/share/doc
MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-configure:
	cd ${WRKSRC}; \
	${SED} /ac_cv_make_ntptime/s/no/yes/ < config.cache > config.cache~; \
	${MV} config.cache~ config.cache
	@${MAKE} do-configure

post-build:
	${SED} 's#@PREFIX@#${PREFIX}#g' < ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

post-install:
	cd ${WRKSRC}; \
	${PAX} -r -w -s "/html/ntp4/" html ${DOCDIR}
	-${RM} -R ${DOCDIR}/ntp4/.cvs*
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR}/ntp4
	${CHMOD} -R ${SHAREMODE} ${DOCDIR}/ntp4
	${CHMOD} a+x ${DOCDIR}/ntp4 ${DOCDIR}/ntp4/hints ${DOCDIR}/ntp4/pic

.include "../../mk/bsd.pkg.mk"
