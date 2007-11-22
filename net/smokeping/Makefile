# $NetBSD: Makefile,v 1.23 2007/11/22 20:25:54 adrianp Exp $

DISTNAME=	smokeping-2.2.7
CATEGORIES=	net
MASTER_SITES=	http://oss.oetiker.ch/smokeping/pub/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://oss.oetiker.ch/smokeping/index.en.html
COMMENT=	Latency/packet loss monitoring/graphing tool

DEPENDS+=	rrdtool>=1.0:../../databases/rrdtool
DEPENDS+=	fping>=2.4b2:../../net/fping
DEPENDS+=	p5-Digest-MD5>=2.20:../../security/p5-Digest-MD5
DEPENDS+=	p5-libwww>=5.64:../../www/p5-libwww

USE_TOOLS+=	perl:run
NO_BUILD=	YES

PKG_SYSCONFSUBDIR?=	smokeping
SMOKEPING_HOME=		${VARBASE}/db/smokeping
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
BUILD_DEFS+=		VARBASE

EGDIR=		${PREFIX}/share/examples/smokeping
SPDIR=		${PREFIX}/share/smokeping
CONF_FILES=	${EGDIR}/basepage.html.dist ${PKG_SYSCONFDIR}/basepage.html
CONF_FILES+=	${EGDIR}/smokemail.dist ${PKG_SYSCONFDIR}/smokemail
CONF_FILES+=	${EGDIR}/config.dist ${PKG_SYSCONFDIR}/config
CONF_FILES+=	${EGDIR}/tmail.dist ${PKG_SYSCONFDIR}/tmail
CONF_FILES+=	${EGDIR}/smokeping.conf ${PKG_SYSCONFDIR}/smokeping.conf
RCD_SCRIPTS=	smokeping
REPLACE_PERL=	bin/smokeping.dist bin/tSmoke.dist

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-patch
SUBST_FILES.files=	bin/smokeping.dist htdocs/smokeping.cgi.dist \
			etc/config.dist etc/smokemail.dist bin/tSmoke.dist \
			etc/basepage.html.dist smokeping.conf
SUBST_SED.files=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.files+=	-e "s|@VARBASE@|${VARBASE}|g"
SUBST_SED.files+=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_SED.files+=	-e "s|@INTERP@|${INTERP}|g"
SUBST_SED.files+=	-e "s|perl-5.8.4|perl|g"
SUBST_SED.files+=	-e "s|/usr/bin/perl|${PERL5}|g"
SUBST_SED.files+=	-e "s|@SPDIR@|${SPDIR}|g"
SUBST_SED.files+=	-e "s|cropper/|/smokeping/cropper/|g"
SUBST_SED.files+=	-e "s|= cache|= /smokeping/.simg|g"
SUBST_MESSAGE.files=	Fixing configuration files.

OWN_DIRS+=		${SMOKEPING_HOME}

INSTALLATION_DIRS=	bin libexec/cgi-bin

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/smokeping.conf ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/Config
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/Config/Grammar
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/Smokeping
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/Smokeping/matchers
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/Smokeping/probes
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smokeping/Smokeping/sorters
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smokeping
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${SPDIR}
	${INSTALL_DATA_DIR} ${SPDIR}/.simg
	${INSTALL_DATA_DIR} ${SPDIR}/cropper

	for FILE in CHANGES CONTRIBUTORS COPYING COPYRIGHT README TODO; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${PREFIX}/share/doc/smokeping; \
	done

	for FILE in ${WRKSRC}/doc/*.txt; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/doc/smokeping; \
	done

	for FILE in ${WRKSRC}/doc/examples/config.*; do \
	  ${INSTALL_DATA} $$FILE ${EGDIR}; \
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

	for FILE in ${WRKSRC}/lib/Config/Grammar/*.pm; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/lib/smokeping/Config/Grammar; \
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

	for FILE in ${WRKSRC}/lib/Smokeping/sorters/*.pm; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/lib/smokeping/Smokeping/sorters; \
	done

	cd ${WRKSRC}/htdocs/cropper && ${PAX} -rw -pm . ${SPDIR}/cropper

	for FILE in ${WRKSRC}/etc/config.dist \
	    ${WRKSRC}/etc/basepage.html.dist \
	    ${WRKSRC}/etc/tmail.dist \
	    ${WRKSRC}/etc/config.dist \
	    ${WRKSRC}/smokeping.conf \
	    ${WRKSRC}/etc/smokemail.dist; do \
	  ${INSTALL_DATA} $$FILE ${EGDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
