# $NetBSD: Makefile,v 1.44 2003/12/07 13:53:32 martti Exp $

DISTNAME=	mrtg-2.10.11
CATEGORIES=	net
MASTER_SITES=	http://people.ee.ethz.ch/~oetiker/webtools/mrtg/pub/ \
		ftp://ftp.sunet.se/pub/network/monitoring/mrtg/ \
		ftp://ftp.chg.ru/pub/networking/management/mrtg/ \
		ftp://ftp.mirrors.wiretapped.net/pub/mrtg/ \
		ftp://ftp.planetmirror.com/pub/oetiker/webtools/mrtg/ \
		ftp://mrtg.pop-mg.com.br/pub/mrtg/pub/ \
		ftp://ftp.130th.net/pub/mirror/mrtg/ \
		ftp://ftp.exobit.org/pub/monitoring/mrtg/ \
		ftp://ftp.ou.edu/mirrors/mrtg/ \
		ftp://ftp.azc.uam.mx/mirrors/mrtg/ \
		ftp://ftp2.cscnet.cz/pub/mirror/mrtg/ \
		ftp://ftp.unipi.it/pub/mirror/mrtg/ \
		ftp://venom.ath.cx/mirror/mrtg/ \
		ftp://ftp.heanet.ie/pub/oetiker/mrtg/ \
		ftp://ftp.nctu.edu.tw/network/mrtg/ \
		ftp://ftp.ayamura.org/pub/mrtg/ \
		ftp://mirror.nucba.ac.jp/mirror/mrtg/ \
		ftp://sunsite.icm.edu.pl/pub/unix/net/mrtg/ \
		ftp://net2b.co.pt/pub/mrtg/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://ee-staff.ethz.ch/~oetiker/webtools/mrtg/mrtg.html
COMMENT=	The Multi-Router Traffic Grapher

USE_BUILDLINK2=	YES
USE_PERL5=	YES
PERL5_REQD=	5.6.1
USE_X11=	YES
GNU_CONFIGURE=	YES

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

.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../graphics/gd/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
