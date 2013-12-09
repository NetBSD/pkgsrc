# $NetBSD: Makefile,v 1.32 2013/12/09 14:17:51 obache Exp $

DISTNAME=	smokeping-2.6.7
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://oss.oetiker.ch/smokeping/pub/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://oss.oetiker.ch/smokeping/index.en.html
COMMENT=	Latency/packet loss monitoring/graphing tool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/db/smokeping
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-htdocs-dir=${PREFIX}/share/httpd/htdocs

DEPENDS+=	rrdtool>=1.0:../../databases/rrdtool
DEPENDS+=	fping>=2.4b2:../../net/fping
DEPENDS+=	{perl>=5.8.0,p5-Digest-MD5>=2.20}:../../security/p5-Digest-MD5
DEPENDS+=	p5-Digest-HMAC>=1.03:../../security/p5-Digest-HMAC
DEPENDS+=	p5-libwww>=5.64:../../www/p5-libwww
DEPENDS+=	p5-FCGI>=0.74:../../www/p5-FCGI
DEPENDS+=	p5-Config-Grammar>=1.10:../../devel/p5-Config-Grammar

USE_TOOLS+=	pax gmake perl:run

PKG_SYSCONFSUBDIR?=	smokeping
SMOKEPING_HOME=		${VARBASE}/db/smokeping
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
BUILD_DEFS+=		VARBASE

EGDIR=			${PREFIX}/share/examples/smokeping
SPDIR=			${PREFIX}/share/smokeping
CONF_FILES=		${EGDIR}/basepage.html.dist \
			${PKG_SYSCONFDIR}/basepage.html
CONF_FILES+=		${EGDIR}/smokemail.dist ${PKG_SYSCONFDIR}/smokemail
CONF_FILES+=		${EGDIR}/smokeping_secrets.dist ${PKG_SYSCONFDIR}/smokeping_secrets
CONF_FILES+=		${EGDIR}/config.dist ${PKG_SYSCONFDIR}/config
CONF_FILES+=		${EGDIR}/tmail.dist ${PKG_SYSCONFDIR}/tmail
CONF_FILES+=		${EGDIR}/smokeping.conf ${PKG_SYSCONFDIR}/smokeping.conf

RCD_SCRIPTS=		smokeping
REPLACE_PERL=		bin/smokeping_cgi bin/smokeping
REPLACE_PERL+=		bin/smokeinfo bin/tSmoke

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-patch
SUBST_FILES.files=	etc/config.dist.in bin/smokeping \
			bin/smokeping_cgi bin/tSmoke \
			htdocs/Makefile.in smokeping.conf
SUBST_SED.files=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.files+=	-e "s|@VARBASE@|${VARBASE}|g"
SUBST_SED.files+=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_SED.files+=	-e "s|@INTERP@|${INTERP}|g"
SUBST_SED.files+=	-e "s|@SPDIR@|${SPDIR}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	post-patch
SUBST_FILES.libs=	bin/smokeping_cgi bin/smokeping bin/smokeinfo bin/tSmoke
SUBST_SED.libs=	-e "s|FindBin::Bin/../lib|FindBin::Bin/../lib/smokeping|g"
SUBST_MESSAGE.libs=	Fixing library path

OWN_DIRS+=		${SMOKEPING_HOME}
OWN_DIRS+=		${SPDIR}/.simg

INSTALLATION_DIRS=	bin libexec/cgi-bin share/httpd/htdocs

post-extract:
	${CP} ${FILESDIR}/smokeping.conf ${WRKSRC}

post-install:
	for FILE in CHANGES CONTRIBUTORS COPYRIGHT LICENSE README TODO; do \
		${INSTALL_DATA} \
		${WRKSRC}/$$FILE ${DESTDIR}${PREFIX}/share/doc/smokeping ; \
	done

	${INSTALL_DATA} ${WRKSRC}/smokeping.conf ${DESTDIR}${EGDIR}

	${MV} ${DESTDIR}${PREFIX}/share/httpd/htdocs/smokeping.fcgi.dist \
		 ${DESTDIR}${PREFIX}/libexec/cgi-bin/smokeping.cgi
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/*.dist ${DESTDIR}${EGDIR}/
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/examples/* ${DESTDIR}${EGDIR}/
	${RMDIR} ${DESTDIR}${PKG_SYSCONFDIR}/examples

.include "options.mk"

INSTALLATION_DIRS+=	lib/smokeping share/doc/smokeping ${EGDIR} \
	${SPDIR}/cropper ${SPDIR}/resource ${SPDIR}/script

.include "../../mk/bsd.pkg.mk"
