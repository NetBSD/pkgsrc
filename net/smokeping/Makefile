# $NetBSD: Makefile,v 1.1.1.1 2003/03/24 15:24:39 bouyer Exp $

DISTNAME=	smokeping-1.19
CATEGORIES=	net
MASTER_SITES=	http://people.ee.ethz.ch/~oetiker/webtools/smokeping/pub/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://people.ee.ethz.ch/~oetiker/webtools/smokeping/index.en.html
COMMENT=	latency/packet loss monitoring/graphing tool

DEPENDS=	rrdtool-1*:../../databases/rrdtool
DEPENDS+=	fping>=2.4b2:../../net/fping
DEPENDS+=	p5-Digest-MD5>=2.20:../../security/p5-Digest-MD5
DEPENDS+=	p5-libwww>=5.64:../../www/p5-libwww

USE_PERL5=	YES
PERL5_REQD=	5.6.0
USE_PKGINSTALL=	yes

PKG_SYSCONFSUBDIR?=     smokeping
MESSAGE_SUBST+=         PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

EGDIR=${PREFIX}/share/examples/smokeping
CONF_FILES= ${EGDIR}/basepage.html.dist ${PKG_SYSCONFDIR}/basepage.html
CONF_FILES+= ${EGDIR}/smokemail.dist ${PKG_SYSCONFDIR}/smokemail
RCD_SCRIPTS=	smokeping

.include "../../mk/bsd.prefs.mk"
.if defined(USE_INET6) && ${USE_INET6} == "YES"
DEPENDS+=	p5-Socket6-*:../../net/p5-Socket6
.endif

do-build:
	${SED} -e s#@PREFIX@#${PREFIX}#g \
	     -e s#@PKG_SYSCONFDIR@#${PKG_SYSCONFDIR}#g \
	     <${WRKSRC}/bin/smokeping.dist >${WRKDIR}/smokeping.pl
	${SED} -e s#@PREFIX@#${PREFIX}#g \
	     -e s#@PKG_SYSCONFDIR@#${PKG_SYSCONFDIR}#g \
	    <${WRKSRC}/htdocs/smokeping.cgi.dist >${WRKDIR}/smokeping.cgi
	${SED} -e s#@PREFIX@#${PREFIX}#g \
	     -e s#@PKG_SYSCONFDIR@#${PKG_SYSCONFDIR}#g \
	    <${WRKSRC}/etc/config.dist >${WRKDIR}/config.dist

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/ISG
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/probes
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smokeping
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/smokeping
	for FILE in CHANGES CONTRIBUTORS COPYING COPYRIGHT README TODO; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${PREFIX}/share/doc/smokeping; \
	done
	for FILE in ${WRKSRC}/doc/*.txt; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/doc/smokeping; \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/smokeping.pl ${PREFIX}/bin/smokeping
	${INSTALL_SCRIPT} ${WRKDIR}/smokeping.cgi ${PREFIX}/libexec/cgi-bin/
	for FILE in ${WRKSRC}/lib/*.pm; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/lib/smokeping; \
	done
	for FILE in ${WRKSRC}/lib/ISG/*.pm; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/lib/smokeping/ISG; \
	done
	for FILE in ${WRKSRC}/lib/probes/*.pm; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/lib/smokeping/probes; \
	done
	for FILE in ${WRKDIR}/config.dist \
	    ${WRKSRC}/etc/basepage.html.dist \
	    ${WRKSRC}/etc/config-echoping.dist \
	    ${WRKSRC}/etc/smokemail.dist; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/examples/smokeping; \
	done

.include "../../mk/bsd.pkg.mk"
