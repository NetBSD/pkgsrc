# $NetBSD: Makefile,v 1.15 2007/05/12 10:00:35 shannonjr Exp $
#

DISTNAME=		prelude-lml-0.9.9
CATEGORIES=		security
MASTER_SITES=		http://www.prelude-ids.org/download/releases/ \
			http://www.prelude-ids.org/download/releases/old/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.prelude-ids.org/download/releases/
COMMENT=		Log analyzer monitoring your logfile and received syslog messages

.include "../../mk/bsd.prefs.mk"

PRELUDE_USER?=		_prelude
PRELUDE_GROUP?=		_prelude

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
PRELUDE_LML_PID_DIR=	${VARBASE}/run/prelude-lml
PRELUDE_HOME=		${VARBASE}/prelude-lml

PKG_GROUPS=	${PRELUDE_GROUP}
PKG_USERS=	${PRELUDE_USER}:${PRELUDE_GROUP}

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

PKG_SYSCONFSUBDIR=	prelude-lml
EGDIR=		share/examples/prelude-lml/
CONF_FILES_PERMS+=	${EGDIR}/plugins.rules ${PKG_SYSCONFDIR}/plugins.rules \
			${ROOT_USER} ${ROOT_GROUP} 0644
CONF_FILES_PERMS+=	${EGDIR}/prelude-lml.conf ${PKG_SYSCONFDIR}/prelude-lml.conf \
			${ROOT_USER} ${ROOT_GROUP} 0644
.for f in apc-emu.rules arbor.rules arpwatch.rules checkpoint.rules \
	cisco-pix.rules cisco-router.rules cisco-vpn.rules clamav.rules \
	dell-om.rules f5-bigip.rules grsecurity.rules honeyd.rules \
	httpd.rules ipchains.rules ipfw.rules ipso.rules linksys-wap11.rules \
	modsecurity.rules ms-sql.rules nagios.rules navce.rules \
	netapp-ontap.rules netfilter.rules netscreen.rules ntsyslog.rules \
	openhostapd.rules pam.rules pcanywhere.rules pcre.rules \
	portsentry.rules postfix.rules proftpd.rules qpopper.rules \
	selinux.rules sendmail.rules shadow-utils.rules single.rules \
	squid.rules ssh.rules sudo.rules tripwire.rules vigor.rules \
	vpopmail.rules webmin.rules wu-ftp.rules zywall.rules zyxel.rules
CONF_FILES+=	${EGDIR}/${f:Q} ${PKG_SYSCONFDIR}/${f:Q}
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
