# $NetBSD: Makefile,v 1.29 2001/11/07 18:26:50 bouyer Exp $
#

DISTNAME=	mrtg-2.9.17
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
COMMENT=	The Multi-Router Traffic Grapher

DEPENDS=	gd>=1.8.1:../../graphics/gd

USE_PERL5=	YES
PERL5_REQD=	5.6.0
USE_X11=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS= --with-gd-inc=${LOCALBASE}/include \
		--with-gd-lib=${LOCALBASE}/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--with-z-lib=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-z-inc=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-png-lib=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-png-inc=${LOCALBASE}/include
.endif

post-build:
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/mrtg.conf.example \
	    >${WRKDIR}/mrtg.conf.example
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/netstat2mrtg \
	    >${WRKDIR}/netstat2mrtg
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/sys2mrtg \
	    >${WRKDIR}/sys2mrtg
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/envstat2mrtg \
	    >${WRKDIR}/envstat2mrtg

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/mrtg
	${INSTALL_DATA_DIR} ${PREFIX}/share/mrtg
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mrtg
	for FILE in ${WRKSRC}/doc/*; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/doc/mrtg; \
	done
	${INSTALL_DATA} ${WRKSRC}/doc/mrtg.1 ${PREFIX}/man/man1
	for FILE in cfgmaker.1 indexmaker.1; do \
	  ${INSTALL_DATA} ${WRKSRC}/doc/$$FILE ${PREFIX}/man/man1/mrtg$$FILE; \
	done
	for FILE in ANNOUNCE CHANGES COPYING COPYRIGHT README; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${PREFIX}/share/doc/mrtg; \
	done
	for FILE in ${WRKSRC}/images/*.png; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/mrtg; \
	done
	${INSTALL_DATA} ${WRKDIR}/mrtg.conf.example ${PREFIX}/etc/mrtg
	for FILE in netstat2mrtg sys2mrtg envstat2mrtg; do \
	  ${INSTALL_SCRIPT} ${WRKDIR}/$$FILE ${PREFIX}/libexec; \
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
	for FILE in cfgmaker indexmaker; do \
	  ${INSTALL_SCRIPT} ${WRKSRC}/bin/$$FILE ${PREFIX}/bin/mrtg$$FILE; \
	done

.include "../../mk/bsd.pkg.mk"
