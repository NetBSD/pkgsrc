# $NetBSD: Makefile,v 1.11 2005/06/17 03:50:28 jlam Exp $

DISTNAME=	smokeping-1.37
CATEGORIES=	net
MASTER_SITES=	http://people.ee.ethz.ch/~oetiker/webtools/smokeping/pub/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://people.ee.ethz.ch/~oetiker/webtools/smokeping/index.en.html
COMMENT=	Latency/packet loss monitoring/graphing tool

DEPENDS=	rrdtool-1*:../../databases/rrdtool
DEPENDS+=	fping>=2.4b2:../../net/fping
DEPENDS+=	p5-Digest-MD5>=2.20:../../security/p5-Digest-MD5
DEPENDS+=	p5-libwww>=5.64:../../www/p5-libwww

USE_PERL5=	YES
PERL5_REQD+=	5.6.0
USE_PKGINSTALL=	YES
NO_BUILD=	YES

BUILD_DEFS+=	USE_INET6

PKG_SYSCONFSUBDIR?=     smokeping
MESSAGE_SUBST+=         PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/smokeping
CONF_FILES= 	${EGDIR}/basepage.html.dist ${PKG_SYSCONFDIR}/basepage.html
CONF_FILES+= 	${EGDIR}/smokemail.dist ${PKG_SYSCONFDIR}/smokemail
RCD_SCRIPTS=	smokeping
REPLACE_PERL=	bin/smokeping.dist

BUILD_DEFS+=	USE_SPEEDY

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
DEPENDS+=	p5-Socket6-*:../../net/p5-Socket6
.endif

.if defined(USE_SPEEDY) && ${USE_SPEEDY} == "YES"
DEPENDS+=	SpeedyCGI-*:../../www/SpeedyCGI
INTERP=		speedy
.else
INTERP=		perl
.endif

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-patch
SUBST_FILES.files=	bin/smokeping.dist htdocs/smokeping.cgi.dist \
			etc/config.dist etc/smokemail.dist
SUBST_SED.files=	-e "s|@PREFIX@|${PREFIX}|g" \
			-e "s|@VARBASE@|${VARBASE}|g" \
			-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g" \
			-e "s|@INTERP@|${INTERP}|g" \
			-e "s|perl-5.8.0|perl|g" \
			-e "s|/usr/bin/perl|${PERL5}|g"
SUBST_MESSAGE.files=	"Fixing configuration files."

INSTALLATION_DIRS=	bin libexec/cgi-bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/ISG
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/matchers
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/probes
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smokeping
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smokeping/matchers
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smokeping/probes
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/smokeping
	for FILE in CHANGES CONTRIBUTORS COPYING COPYRIGHT README TODO; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${PREFIX}/share/doc/smokeping; \
	done
	for FILE in ${WRKSRC}/doc/*.txt; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/doc/smokeping; \
	done
	for FILE in ${WRKSRC}/doc/matchers/*.txt; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/doc/smokeping/matchers; \
	done
	for FILE in ${WRKSRC}/doc/probes/*.txt; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/doc/smokeping/probes; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/bin/smokeping.dist \
		${PREFIX}/bin/smokeping
	${INSTALL_SCRIPT} ${WRKSRC}/htdocs/smokeping.cgi.dist \
		${PREFIX}/libexec/cgi-bin/smokeping.cgi
	for FILE in ${WRKSRC}/lib/*.pm; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/lib/smokeping; \
	done
	for FILE in ${WRKSRC}/lib/ISG/*.pm; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/lib/smokeping/ISG; \
	done
	for FILE in ${WRKSRC}/lib/probes/*.pm; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/lib/smokeping/probes; \
	done
	for FILE in ${WRKSRC}/lib/matchers/*.pm; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/lib/smokeping/matchers; \
	done
	for FILE in ${WRKSRC}/etc/config.dist \
	    ${WRKSRC}/etc/basepage.html.dist \
	    ${WRKSRC}/etc/config-echoping.dist \
	    ${WRKSRC}/etc/smokemail.dist; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/examples/smokeping; \
	done

.include "../../mk/bsd.pkg.mk"
