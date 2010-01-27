# $NetBSD: Makefile,v 1.27 2010/01/27 17:40:30 joerg Exp $

DISTNAME=	smokeping-2.4.2
CATEGORIES=	net
MASTER_SITES=	http://oss.oetiker.ch/smokeping/pub/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://oss.oetiker.ch/smokeping/index.en.html
COMMENT=	Latency/packet loss monitoring/graphing tool

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	rrdtool>=1.0:../../databases/rrdtool
DEPENDS+=	fping>=2.4b2:../../net/fping
DEPENDS+=	p5-Digest-MD5>=2.20:../../security/p5-Digest-MD5
DEPENDS+=	p5-libwww>=5.64:../../www/p5-libwww

USE_TOOLS+=	pax perl:run
NO_BUILD=	YES

PKG_SYSCONFSUBDIR?=	smokeping
SMOKEPING_HOME=		${VARBASE}/db/smokeping
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
BUILD_DEFS+=		VARBASE

EGDIR=			${PREFIX}/share/examples/smokeping
SPDIR=			${PREFIX}/share/smokeping
CONF_FILES=		${EGDIR}/basepage.html.dist \
			${PKG_SYSCONFDIR}/basepage.html
CONF_FILES+=		${EGDIR}/smokemail.dist ${PKG_SYSCONFDIR}/smokemail
CONF_FILES+=		${EGDIR}/config.dist ${PKG_SYSCONFDIR}/config
CONF_FILES+=		${EGDIR}/tmail.dist ${PKG_SYSCONFDIR}/tmail
CONF_FILES+=		${EGDIR}/smokeping.conf ${PKG_SYSCONFDIR}/smokeping.conf
RCD_SCRIPTS=		smokeping
REPLACE_PERL=		bin/smokeping.dist bin/tSmoke.dist

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-patch
SUBST_FILES.files=	bin/smokeping.dist htdocs/smokeping.cgi.dist \
			etc/config.dist etc/smokemail.dist bin/tSmoke.dist \
			etc/basepage.html.dist smokeping.conf htdocs/tr.cgi.dist
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
OWN_DIRS+=		${SPDIR}/.simg

INSTALLATION_DIRS=	bin libexec/cgi-bin

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/smokeping.conf ${WRKSRC}

INSTALLATION_DIRS+=	lib/smokeping share/doc/smokeping ${EGDIR} \
	${SPDIR}/cropper ${SPDIR}/resource ${SPDIR}/script

do-install:
	for FILE in CHANGES CONTRIBUTORS COPYING COPYRIGHT README TODO; do \
		${INSTALL_DATA} \
			${WRKSRC}/$$FILE ${DESTDIR}${PREFIX}/share/doc/smokeping; \
	done

	for FILE in ${WRKSRC}/doc/*.txt; do \
		${INSTALL_DATA} $$FILE ${DESTDIR}${PREFIX}/share/doc/smokeping; \
	done

	for FILE in ${WRKSRC}/doc/examples/config.*; do \
		${INSTALL_DATA} $$FILE ${DESTDIR}${EGDIR}; \
	done

	${INSTALL_SCRIPT} ${WRKSRC}/bin/smokeping.dist ${DESTDIR}${PREFIX}/bin/smokeping
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tSmoke.dist ${DESTDIR}${PREFIX}/bin/tSmoke

	${INSTALL_SCRIPT} ${WRKSRC}/htdocs/smokeping.cgi.dist \
		${DESTDIR}${PREFIX}/libexec/cgi-bin/smokeping.cgi
	${INSTALL_SCRIPT} ${WRKSRC}/htdocs/tr.cgi.dist \
		${DESTDIR}${PREFIX}/libexec/cgi-bin/tr.cgi

	cd ${WRKSRC}/htdocs/cropper && pax -rw -pm . ${DESTDIR}${SPDIR}/cropper
	cd ${WRKSRC}/htdocs/resource && pax -rw -pm . ${DESTDIR}${SPDIR}/resource
	cd ${WRKSRC}/htdocs/script && pax -rw -pm . ${DESTDIR}${SPDIR}/script
	cd ${WRKSRC}/lib && pax -rw -pm . ${DESTDIR}${PREFIX}/lib/smokeping
	${INSTALL_DATA} ${WRKSRC}/htdocs/tr.html ${DESTDIR}${SPDIR}

	for FILE in ${WRKSRC}/etc/config.dist \
		${WRKSRC}/etc/basepage.html.dist \
		${WRKSRC}/etc/tmail.dist \
		${WRKSRC}/etc/config.dist \
		${WRKSRC}/smokeping.conf \
		${WRKSRC}/etc/smokemail.dist; do \
		${INSTALL_DATA} $$FILE ${DESTDIR}${EGDIR}; \
	done

	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/lib/smokeping/JSON/*.pm
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/lib/smokeping/JSON.pm

.include "../../mk/bsd.pkg.mk"
