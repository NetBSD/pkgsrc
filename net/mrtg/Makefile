# $NetBSD: Makefile,v 1.15 2000/03/17 23:19:54 tron Exp $
# FreeBSD Id: Makefile,v 1.7 1997/12/16 19:42:17 vanilla Exp
#

DISTNAME=	mrtg-2.8.12
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

DEPENDS=	gd>=1.7.3:../../graphics/gd

USE_PERL5=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --with-gd-inc=${LOCALBASE}/include \
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
