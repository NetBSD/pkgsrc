# $NetBSD: Makefile,v 1.10 1999/08/28 23:25:30 kim Exp $
# FreeBSD Id: Makefile,v 1.7 1997/12/16 19:42:17 vanilla Exp
#

DISTNAME=	mrtg-2.8.8
CATEGORIES=	net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/mrtg/pub/ \
		http://gd.tuwien.ac.at/infosys/network/tools/mrtg/pub/ \
		ftp://mrtg.hdl.com/ \
		ftp://ftp.sunet.se/pub/network/monitoring/mrtg/ \
		ftp://ftp.ou.edu/mirrors/mrtg/ \
		ftp://eesa.webstar.co.uk/pub/mrtg/ \
		ftp://ftp.chg.ru/pub/networking/management/mrtg/ \
		ftp://ftp.onet.pl/pub/unix/network/mrtg/pub/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://ee-staff.ethz.ch/~oetiker/webtools/mrtg/mrtg.html

DEPENDS=	gd-1.6.3:../../graphics/gd

USE_PERL5=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-gd-inc=${PREFIX}/include --with-gd-lib=${PREFIX}/lib

post-build:
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/mrtg.conf.example \
	    >${WRKDIR}/mrtg.conf.example
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/netstat2mrtg \
	    >${WRKDIR}/netstat2mrtg
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/sys2mrtg \
	    >${WRKDIR}/sys2mrtg

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
	for file in ${WRKSRC}/images/*.gif; do \
		${INSTALL_DATA} $$file ${PREFIX}/share/mrtg/; \
	done
	${INSTALL_DATA} ${WRKDIR}/mrtg.conf.example ${PREFIX}/etc/mrtg
	for file in netstat2mrtg sys2mrtg; do \
		${INSTALL_SCRIPT} ${WRKDIR}/$$file ${PREFIX}/libexec/; \
	done
	${INSTALL_PROGRAM} ${WRKSRC}/run/rateup ${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/run/mrtg ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/run/BER.pm ${WRKSRC}/run/SNMP_Session.pm \
		${WRKSRC}/run/SNMP_util.pm ${WRKSRC}/run/locales_mrtg.pm \
		${PREFIX}/lib/perl5/site_perl/
	for file in cfgmaker cfgmaker_ip indexmaker; do \
		${INSTALL_SCRIPT} ${WRKSRC}/run/$$file \
			${PREFIX}/bin/mrtg$$file; \
	done

.include "../../mk/bsd.pkg.mk"
