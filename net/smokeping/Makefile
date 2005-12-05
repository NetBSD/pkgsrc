# $NetBSD: Makefile,v 1.15 2005/12/05 20:50:49 rillig Exp $

DISTNAME=	smokeping-2.0.4
CATEGORIES=	net
MASTER_SITES=	http://people.ee.ethz.ch/~oetiker/webtools/smokeping/pub/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://people.ee.ethz.ch/~oetiker/webtools/smokeping/index.en.html
COMMENT=	Latency/packet loss monitoring/graphing tool

DEPENDS+=	rrdtool>=1.0:../../databases/rrdtool
DEPENDS+=	fping>=2.4b2:../../net/fping
DEPENDS+=	p5-Digest-MD5>=2.20:../../security/p5-Digest-MD5
DEPENDS+=	p5-libwww>=5.64:../../www/p5-libwww

USE_TOOLS+=	perl:run
USE_PKGINSTALL=	YES
NO_BUILD=	YES

BUILD_DEFS+=	USE_INET6

PKG_SYSCONFSUBDIR?=     smokeping
SMOKEPING_HOME=		${VARBASE}/db/smokeping
MESSAGE_SUBST+=         PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/smokeping
CONF_FILES= 	${EGDIR}/basepage.html.dist ${PKG_SYSCONFDIR}/basepage.html
CONF_FILES+= 	${EGDIR}/smokemail.dist ${PKG_SYSCONFDIR}/smokemail
CONF_FILES+= 	${EGDIR}/config.dist ${PKG_SYSCONFDIR}/config
CONF_FILES+= 	${EGDIR}/tmail.dist ${PKG_SYSCONFDIR}/tmail
RCD_SCRIPTS=	smokeping
REPLACE_PERL=	bin/smokeping.dist bin/tSmoke.dist

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
			etc/config.dist etc/smokemail.dist bin/tSmoke.dist
SUBST_SED.files=	-e "s|@PREFIX@|${PREFIX}|g" \
			-e "s|@VARBASE@|${VARBASE}|g" \
			-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g" \
			-e "s|@INTERP@|${INTERP}|g" \
			-e "s|perl-5.8.4|perl|g" \
			-e "s|/usr/bin/perl|${PERL5}|g"
SUBST_MESSAGE.files=	"Fixing configuration files."

OWN_DIRS+=		${SMOKEPING_HOME} 

INSTALLATION_DIRS=	bin libexec/cgi-bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/Config
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/Smokeping
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/Smokeping/matchers
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/Smokeping/probes
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smokeping
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/smokeping

	for FILE in CHANGES CONTRIBUTORS COPYING COPYRIGHT README TODO; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${PREFIX}/share/doc/smokeping; \
	done

	for FILE in ${WRKSRC}/doc/*.txt; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/doc/smokeping; \
	done

	for FILE in ${WRKSRC}/doc/examples/config.*; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/examples/smokeping; \
	done

	${INSTALL_SCRIPT} ${WRKSRC}/bin/smokeping.dist ${PREFIX}/bin/smokeping
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tSmoke.dist ${PREFIX}/bin/tSmoke

	${INSTALL_SCRIPT} ${WRKSRC}/htdocs/smokeping.cgi.dist \
		${PREFIX}/libexec/cgi-bin/smokeping.cgi

	for FILE in ${WRKSRC}/lib/*.pm; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/lib/smokeping; \
	done

	for FILE in ${WRKSRC}/lib/Config/*.pm; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/lib/smokeping/Config; \
	done

	for FILE in ${WRKSRC}/lib/Smokeping/*.pm; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/lib/smokeping/Smokeping; \
	done

	for FILE in ${WRKSRC}/lib/Smokeping/matchers/*.pm; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/lib/smokeping/Smokeping/matchers; \
	done

	for FILE in ${WRKSRC}/lib/Smokeping/probes/*.pm; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/lib/smokeping/Smokeping/probes; \
	done

	for FILE in ${WRKSRC}/etc/config.dist \
	    ${WRKSRC}/etc/basepage.html.dist \
	    ${WRKSRC}/etc/tmail.dist \
	    ${WRKSRC}/etc/config.dist \
	    ${WRKSRC}/etc/smokemail.dist; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/examples/smokeping; \
	done

.include "../../mk/bsd.pkg.mk"
