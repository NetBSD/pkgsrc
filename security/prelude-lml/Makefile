# $NetBSD: Makefile,v 1.23 2008/04/28 10:54:08 shannonjr Exp $
#

DISTNAME=		prelude-lml-0.9.12.2
CATEGORIES=		security
MASTER_SITES=		http://www.prelude-ids.org/download/releases/ \
			http://www.prelude-ids.org/download/releases/old/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.prelude-ids.org/download/releases/
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
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--disable-fam
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
RCD_SCRIPTS=		preludelml
PRELUDE_USER?=		_prelude
PRELUDE_GROUP?=		_prelude
BUILD_DEFS+=		VARBASE
PRELUDE_LML_PID_DIR=	${VARBASE}/run/prelude-lml
PRELUDE_HOME=		${VARBASE}/prelude-lml

PKG_GROUPS=		${PRELUDE_GROUP}
PKG_USERS=		${PRELUDE_USER}:${PRELUDE_GROUP}

EGDIR=			${PREFIX}/share/examples/prelude-lml
REQD_DIRS=		${EGDIR}
MAKE_DIRS+=		${VARBASE}/prelude-lml PKG_SYSCONFDIR
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
	httpd.rules             \
	ipchains.rules          \
	ipfw.rules              \
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
	proftpd.rules           \
	qpopper.rules           \
	selinux.rules           \
	sendmail.rules          \
	shadow-utils.rules      \
	single.rules            \
	sonicwall.rules         \
	spamassassin.rules      \
	squid.rules             \
	ssh.rules               \
	sudo.rules              \
	tripwire.rules          \
	vigor.rules             \
	vpopmail.rules          \
	linksys-wap11.rules     \
	webmin.rules            \
	wu-ftp.rules
.for f in ${ruleset_DATA}
CONF_FILES+=	${EGDIR}/ruleset/${f:Q} ${PKG_SYSCONFDIR}/ruleset/${f:Q}
.endfor

pre-patch:
	${CP} ${FILESDIR}/run-prelude-lml.c ${WRKSRC}

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o run-prelude-lml run-prelude-lml.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/run-prelude-lml ${PREFIX}/sbin/run-prelude-lml
	${CHOWN} -R ${PRELUDE_USER}:${PRELUDE_GROUP} ${PRELUDE_HOME}

.include "../../security/libprelude/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
