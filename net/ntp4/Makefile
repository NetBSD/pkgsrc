# $NetBSD: Makefile,v 1.2 1999/07/24 19:02:40 fredb Exp $
#

DISTNAME=	ntp-4.0.94a
CATEGORIES=	net
MASTER_SITES=	http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ \
		ftp://ftp.udel.edu/pub/ntp/ntp4/

MAINTAINER=	fb@enteract.com
HOMEPAGE=	http:/www.ntp.org/

GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/ntp-4.0.94
DOCDIR=		${PREFIX}/share/doc

post-configure:
	cd ${WRKSRC}; \
	${SED} /ac_cv_make_ntptime/s/no/yes/ < config.cache > config.cache~; \
	${MV} config.cache~ config.cache
	@${MAKE} do-configure

post-install:
	cd ${WRKSRC}; \
	${PAX} -r -w -s "/html/ntp4/" html ${DOCDIR}
	-${RM} -R ${DOCDIR}/ntp4/.cvs*
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR}/ntp4
	${CHMOD} -R ${SHAREMODE} ${DOCDIR}/ntp4
	${CHMOD} a+x ${DOCDIR}/ntp4 ${DOCDIR}/ntp4/hints ${DOCDIR}/ntp4/pic

.include "../../mk/bsd.pkg.mk"
