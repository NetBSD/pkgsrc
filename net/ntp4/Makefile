# $NetBSD: Makefile,v 1.7 1999/08/13 08:54:28 fredb Exp $
#

DISTNAME=	ntp-4.0.95
PKGNAME=	ntp-4.0.96p1
CATEGORIES=	net
MASTER_SITES=	http://www.eecis.udel.edu/~ntp/ntp_spool/testing/ \
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ \
		ftp://ftp.udel.edu/pub/ntp/testing/ \
		ftp://ftp.udel.edu/pub/ntp/ntp4/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	ntp-4.0.95-4.0.96.diff.gz ntp-4.0.96-4.0.96p1.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	fb@enteract.com
HOMEPAGE=	http://www.ntp.org/

BUILD_DEPENDS+=	autoconf:../../devel/autoconf
BUILD_DEPENDS+=	automake:../../devel/automake

# gmake, automake, autoconf are only required for patch releases

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

DOCDIR=		${PREFIX}/share/doc
EXAMPLESDIR=	${PREFIX}/share/examples
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
	${PAX} -r -w -s "/html/ntp4/" html ${DOCDIR}; \
	${PAX} -r -w -s "/conf/ntp4/" conf ${EXAMPLESDIR}
	-${RM} ${DOCDIR}/ntp4/.cvs* ${DOCDIR}/ntp4/*.orig ${DOCDIR}/ntp4/hints/*.orig
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR}/ntp4 ${EXAMPLESDIR}/ntp4
	${CHMOD} -R ${SHAREMODE} ${DOCDIR}/ntp4 ${EXAMPLESDIR}/ntp4
	${CHMOD} a+x ${DOCDIR}/ntp4 ${DOCDIR}/ntp4/hints ${DOCDIR}/ntp4/pic
	${CHMOD} a+x ${EXAMPLESDIR}/ntp4

.include "../../mk/bsd.pkg.mk"
