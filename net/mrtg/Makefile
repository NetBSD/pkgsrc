# $NetBSD: Makefile,v 1.20 2000/10/23 13:47:53 bouyer Exp $
# FreeBSD Id: Makefile,v 1.7 1997/12/16 19:42:17 vanilla Exp
#

DISTNAME=	mrtg-2.9.2
CATEGORIES=	net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/mrtg/pub/ \
		http://gd.tuwien.ac.at/infosys/network/tools/mrtg/pub/ \
		ftp://mrtg.hdl.com/ \
		ftp://ftp.sunet.se/pub/network/monitoring/mrtg/ \
		ftp://ftp.ou.edu/mirrors/mrtg/ \
		ftp://eesa.webstar.co.uk/pub/mrtg/ \
		ftp://ftp.chg.ru/pub/networking/management/mrtg/ \
		ftp://ftp.onet.pl/pub/unix/network/mrtg/pub/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://ee-staff.ethz.ch/~oetiker/webtools/mrtg/mrtg.html

DEPENDS=	gd>=1.8.1:../../graphics/gd

USE_PERL5=	# defined
USE_X11=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ARGS= --with-gd-inc=${LOCALBASE}/include \
		--with-gd-lib=${LOCALBASE}/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--with-z-lib=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-z-inc=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-png-lib=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-png-inc=${LOCALBASE}/include
.endif

MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-build:
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/mrtg.conf.example \
	    >${WRKDIR}/mrtg.conf.example
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/netstat2mrtg \
	    >${WRKDIR}/netstat2mrtg
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/sys2mrtg \
	    >${WRKDIR}/sys2mrtg
	${SED} s#@PREFIX@#${PREFIX}#g <${PKGDIR}/MESSAGE \
	    >${MESSAGE_FILE}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/mrtg
	${INSTALL_DATA_DIR} ${PREFIX}/share/mrtg
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mrtg
	for file in ${WRKSRC}/doc/*; do \
		${INSTALL_DATA} $$file ${PREFIX}/share/doc/mrtg/; \
	done
	for file in ANNOUNCE CHANGES COPYING COPYRIGHT README; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/share/doc/mrtg/; \
	done
	for file in ${WRKSRC}/images/*.png; do \
		${INSTALL_DATA} $$file ${PREFIX}/share/mrtg/; \
	done
	${INSTALL_DATA} ${WRKDIR}/mrtg.conf.example ${PREFIX}/etc/mrtg
	for file in netstat2mrtg sys2mrtg; do \
		${INSTALL_SCRIPT} ${WRKDIR}/$$file ${PREFIX}/libexec/; \
	done
	${INSTALL_DATA_DIR} ${PERL5_SITELIB}
	${INSTALL_SCRIPT} ${WRKSRC}/lib/mrtg2/BER.pm \
	    ${WRKSRC}/lib/mrtg2/SNMP_Session.pm \
	    ${WRKSRC}/lib/mrtg2/SNMP_util.pm \
	    ${WRKSRC}/lib/mrtg2/MRTG_lib.pm \
	    ${WRKSRC}/lib/mrtg2/locales_mrtg.pm \
		${PERL5_SITELIB}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rateup ${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mrtg ${PREFIX}/bin/
	for file in cfgmaker indexmaker; do \
		${INSTALL_SCRIPT} ${WRKSRC}/bin/$$file \
			${PREFIX}/bin/mrtg$$file; \
	done

.include "../../mk/bsd.pkg.mk"
