# $NetBSD: Makefile,v 1.49 2022/06/28 11:35:20 wiz Exp $

DISTNAME=	smokeping-2.7.3
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://oss.oetiker.ch/smokeping/pub/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://oss.oetiker.ch/smokeping/index.en.html
COMMENT=	Latency/packet loss monitoring/graphing tool
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/db/smokeping
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-htdocs-dir=${PREFIX}/share/smokeping

DEPENDS+=	rrdtool>=1.0:../../databases/rrdtool
DEPENDS+=	fping>=2.4b2:../../net/fping
#DEPENDS+=	{perl>=5.8.0,p5-Digest-MD5>=2.20}:../../security/p5-Digest-MD5
DEPENDS+=	p5-Config-Grammar>=1.10:../../devel/p5-Config-Grammar
DEPENDS+=	p5-Path-Tiny>=0.108:../../filesystems/p5-Path-Tiny
DEPENDS+=	p5-Socket6>=0.29:../../net/p5-Socket6
DEPENDS+=	p5-Net-Telnet>=3.04:../../net/p5-Net-Telnet
DEPENDS+=	p5-Net-SNMP>=v6.0.1:../../net/p5-Net-SNMP
DEPENDS+=	p5-Net-DNS>=1.23:../../net/p5-Net-DNS
DEPENDS+=	p5-Digest-HMAC>=1.03:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Net-OpenSSH>=0.78:../../security/p5-Net-OpenSSH
DEPENDS+=	p5-IO-Socket-SSL>=2.067:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Digest-HMAC>=1.03:../../security/p5-Digest-HMAC
DEPENDS+=	p5-FCGI>=0.74:../../www/p5-FCGI
DEPENDS+=	p5-CGI>=4.20:../../www/p5-CGI
DEPENDS+=	p5-CGI-Fast>=2.09:../../www/p5-CGI-Fast
DEPENDS+=	p5-libwww>=6.43:../../www/p5-libwww

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
SUBST_STAGE.files=	pre-configure
SUBST_FILES.files=	etc/config.dist.in bin/smokeping \
			bin/smokeping_cgi bin/tSmoke \
			htdocs/Makefile.in smokeping.conf
SUBST_VARS.files=	PREFIX
SUBST_VARS.files+=	VARBASE
SUBST_VARS.files+=	PKG_SYSCONFDIR
SUBST_VARS.files+=	INTERP
SUBST_VARS.files+=	SPDIR
SUBST_MESSAGE.files=	Fixing configuration files.

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	pre-configure
SUBST_FILES.libs=	bin/smokeping_cgi bin/smokeping bin/smokeinfo bin/tSmoke
SUBST_SED.libs=		-e "s|FindBin::RealBin/../lib|FindBin::RealBin/../lib/smokeping|g"
SUBST_MESSAGE.libs=	Fixing library path

OWN_DIRS+=		${SMOKEPING_HOME}
OWN_DIRS+=		${SPDIR}/.simg

INSTALLATION_DIRS=	bin libexec/cgi-bin share/smokeping

post-extract:
	${CP} ${FILESDIR}/smokeping.conf ${WRKSRC}

post-install:
	for FILE in CHANGES CONTRIBUTORS COPYRIGHT LICENSE README TODO; do \
		${INSTALL_DATA} \
		${WRKSRC}/$$FILE ${DESTDIR}${PREFIX}/share/doc/smokeping ; \
	done

	${INSTALL_DATA} ${WRKSRC}/smokeping.conf ${DESTDIR}${EGDIR}

	${MV} ${DESTDIR}${PREFIX}/share/smokeping/smokeping.fcgi.dist \
		 ${DESTDIR}${PREFIX}/libexec/cgi-bin/smokeping.cgi
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/*.dist ${DESTDIR}${EGDIR}/
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/examples/* ${DESTDIR}${EGDIR}/
	${RMDIR} ${DESTDIR}${PKG_SYSCONFDIR}/examples

.include "options.mk"

INSTALLATION_DIRS+=	lib/smokeping share/doc/smokeping ${EGDIR} \
			${SPDIR}/cropper ${SPDIR}/resource ${SPDIR}/script

.include "../../mk/bsd.pkg.mk"
