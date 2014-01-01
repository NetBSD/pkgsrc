# $NetBSD: Makefile,v 1.37 2014/01/01 11:52:33 wiz Exp $
#

DISTNAME=		prelude-lml-0.9.15
PKGREVISION=		6
CATEGORIES=		security
MASTER_SITES=		http://www.prelude-ids.com/download/releases/prelude-lml/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.prelude-ids.org/
COMMENT=		Log analyzer monitoring your logfile and received syslog messages

.include "../../mk/bsd.prefs.mk"

PRELUDE_USER?=		_prelude
PRELUDE_GROUP?=		_prelude

PKG_GROUPS_VARS+=	PRELUDE_GROUP
PKG_USERS_VARS+=	PRELUDE_USER

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--html=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
RCD_SCRIPTS=		preludelml
PRELUDE_USER?=		_prelude
PRELUDE_GROUP?=		_prelude
BUILD_DEFS+=		VARBASE
PRELUDE_LML_PID_DIR=	${VARBASE}/run/prelude-lml
PRELUDE_HOME=		${VARBASE}/prelude-lml

INSTALLATION_DIRS=	sbin

PKG_GROUPS=		${PRELUDE_GROUP}
PKG_USERS=		${PRELUDE_USER}:${PRELUDE_GROUP}

EGDIR=			${PREFIX}/share/examples/prelude-lml
REQD_DIRS=		${EGDIR} ${PKG_SYSCONFDIR}/ruleset
MAKE_DIRS_PERMS+=	${VARBASE}/prelude-lml	${PRELUDE_USER} ${PRELUDE_GROUP} 0700

PKG_GECOS.${PRELUDE_USER}=	Prelude IDS
PKG_HOME.${PRELUDE_USER}=	${PRELUDE_HOME}

FILES_SUBST+=	PRELUDE_LML_PID_DIR=${PRELUDE_LML_PID_DIR:Q}
FILES_SUBST+=	PRELUDE_USER=${PRELUDE_USER:Q}
FILES_SUBST+=	PRELUDE_GROUP=${PRELUDE_GROUP:Q}

SUBST_CLASSES+=		code
SUBST_STAGE.code=	post-patch
SUBST_FILES.code=	run-prelude-lml.c
SUBST_SED.code=		-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.code+=	-e 's,@PRELUDE_USER@,${PRELUDE_USER},g'

SUBST_CLASSES+=		make
SUBST_STAGE.make=	post-patch
SUBST_FILES.make=	Makefile.in
SUBST_SED.make=		-e 's,@EGDIR@,${EGDIR},g'

PKG_SYSCONFSUBDIR=	prelude-lml
CONF_FILES_PERMS+=	${EGDIR}/plugins.rules ${PKG_SYSCONFDIR}/plugins.rules \
			${ROOT_USER} ${ROOT_GROUP} 0644
CONF_FILES_PERMS+=	${EGDIR}/prelude-lml.conf ${PKG_SYSCONFDIR}/prelude-lml.conf \
			${ROOT_USER} ${ROOT_GROUP} 0644

# From plugins/pcre/ruleset/Makefile.in
ruleset_DATA = \
	apc-emu.rules           \
	arbor.rules             \
	arpwatch.rules          \
	asterisk.rules		\
	bonding.rules           \
	cacti-thold.rules       \
	checkpoint.rules        \
	cisco-asa.rules         \
	cisco-common.rules      \
	cisco-css.rules         \
	cisco-ips.rules         \
	cisco-router.rules      \
	cisco-vpn.rules         \
	clamav.rules            \
	dell-om.rules           \
	f5-bigip.rules          \
	grsecurity.rules        \
	honeyd.rules            \
	honeytrap.rules		\
	httpd.rules             \
	ipchains.rules          \
	ipfw.rules              \
	kojoney.rules		\
	modsecurity.rules       \
	ms-cluster.rules        \
	ms-sql.rules            \
	nagios.rules            \
	navce.rules             \
	netapp-ontap.rules      \
	netfilter.rules         \
	netscreen.rules         \
	ntsyslog.rules          \
	openhostapd.rules       \
	pam.rules               \
	pcanywhere.rules        \
	pcre.rules              \
	portsentry.rules        \
	postfix.rules           \
	ppp.rules		\
	proftpd.rules           \
	qpopper.rules           \
	rishi.rules		\
	selinux.rules           \
	sendmail.rules          \
	shadow-utils.rules      \
	single.rules            \
	sonicwall.rules         \
	spamassassin.rules      \
	squid.rules             \
	su.rules		\
	ssh.rules               \
	sudo.rules              \
	suhosin.rules		\
	tripwire.rules          \
	vigor.rules             \
	vpopmail.rules          \
	linksys-wap11.rules     \
	webmin.rules            \
	wu-ftp.rules
.for f in ${ruleset_DATA}
CONF_FILES+=	${EGDIR}/ruleset/${f:Q} ${PKG_SYSCONFDIR}/ruleset/${f:Q}
.endfor

PKG_OPTIONS_VAR=	PKG_OPTIONS.prelude-lml
PKG_SUPPORTED_OPTIONS=	unsupported-rulesets

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		unsupported
.if !empty(PKG_OPTIONS:Munsupported-rulesets)
CONFIGURE_ARGS+=	--enable-unsupported-rulesets
PLIST.unsupported=	yes
unsupported_ruleset_DATA = \
	exim.rules		\
	ipso.rules		\
	zywall.rules		\
	zyxel.rules
.  for f in ${unsupported_ruleset_DATA}
CONF_FILES+=	${EGDIR}/ruleset/${f:Q} ${PKG_SYSCONFDIR}/ruleset/${f:Q}
.  endfor
.endif

pre-patch:
	${CP} ${FILESDIR}/run-prelude-lml.c ${WRKSRC}

pre-configure:
	${LN} -s ${BUILDLINK_DIR}/lib/libltdl.so ${BUILDLINK_DIR}/lib/libltdlc.so

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o run-prelude-lml run-prelude-lml.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/run-prelude-lml ${DESTDIR}${PREFIX}/sbin/run-prelude-lml

.include "../../security/libprelude/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
