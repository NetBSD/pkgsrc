# $NetBSD: Makefile,v 1.10 1999/11/14 05:23:26 fredb Exp $
#

DISTNAME=	ntp-4.0.98f
CATEGORIES=	net
MASTER_SITES=	http://www.eecis.udel.edu/~ntp/ntp_spool/testing/ \
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ \
		ftp://ftp.udel.edu/pub/ntp/testing/ \
		ftp://ftp.udel.edu/pub/ntp/ntp4/

MAINTAINER=	fb@enteract.com
HOMEPAGE=	http://www.ntp.org/

GNU_CONFIGURE=	YES

DOCDIR=		${PREFIX}/share/doc
EXAMPLESDIR=	${PREFIX}/share/examples
MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-build:
	${SED} 's#@PREFIX@#${PREFIX}#g' < ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

post-install:
	cd ${WRKSRC}; \
	    ${RM} html/.cvsignore* 2> /dev/null || true; \
	    ${PAX} -r -w -s "/html/ntp4/" html ${DOCDIR}; \
	    ${PAX} -r -w -s "/conf/ntp4/" conf ${EXAMPLESDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR}/ntp4 ${EXAMPLESDIR}/ntp4
	${CHMOD} -R ${SHAREMODE} ${DOCDIR}/ntp4 ${EXAMPLESDIR}/ntp4
	${CHMOD} a+x ${DOCDIR}/ntp4 ${DOCDIR}/ntp4/hints ${DOCDIR}/ntp4/pic
	${CHMOD} a+x ${EXAMPLESDIR}/ntp4

.include "../../mk/bsd.pkg.mk"
