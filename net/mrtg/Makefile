# $NetBSD: Makefile,v 1.4 1998/08/20 15:17:17 tsarna Exp $
# FreeBSD Id: Makefile,v 1.7 1997/12/16 19:42:17 vanilla Exp
#

DISTNAME=	mrtg-2.5.3
CATEGORIES=	net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/mrtg/pub/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://ee-staff.ethz.ch/~oetiker/webtools/mrtg/mrtg.html

DEPENDS=	gd-1.3:../../graphics/gd

USE_PERL5=	YES

ALL_TARGET=	rateup substitute

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/mrtg
	${INSTALL_DATA_DIR} ${PREFIX}/share/mrtg
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mrtg
	for file in mrtg-conf.html mrtg-conf.txt readme.html readme.txt mibhelp.txt COPYING COPYRIGHT; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/share/doc/mrtg/; \
	done
	for file in ${WRKSRC}/*.gif; do \
		${INSTALL_DATA} $$file ${PREFIX}/share/mrtg/; \
	done
	${INSTALL_PROGRAM} ${WRKSRC}/rateup ${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/mrtg ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/BER.pm ${WRKSRC}/SNMP_Session.pm \
		${PREFIX}/lib/perl5/site_perl/
	for file in cfgmaker convert indexmaker; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$file ${PREFIX}/bin/mrtg$$file; \
	done

.include "../../mk/bsd.pkg.mk"
