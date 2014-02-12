# $NetBSD: Makefile,v 1.83 2014/02/12 23:18:20 tron Exp $

DISTNAME=	freeradius-${RADVER}
PKGREVISION=	9
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freeradius.org/
COMMENT=	Free RADIUS server implementation

CONFLICTS+=	freeradius-2.[0-9]*

MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=		radiusd-cistron-[0-9]*
USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_OLD_DES_API=	YES

BUILD_DEFS+=		VARBASE
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
FILES_SUBST+=		RADIUS_USER=${RADIUS_USER}
FILES_SUBST+=		RADIUS_GROUP=${RADIUS_GROUP}
PLIST_SUBST+=		RADVER=${RADVER}
MESSAGE_SRC+=		${WRKDIR}/.MESSAGE_SRC
MESSAGE_SUBST+=		CHOWN=${CHOWN:Q} CHMOD=${CHMOD:Q} VARBASE=${VARBASE}
MESSAGE_SUBST+=		RADIUS_USER=${RADIUS_USER} XARGS=${XARGS:Q}
MESSAGE_SUBST+=		RADIUS_GROUP=${RADIUS_GROUP} FIND=${FIND:Q}

PKG_SYSCONFSUBDIR=	raddb
RCD_SCRIPTS=		radiusd
RADIUS_USER?=		radius
RADIUS_GROUP?=		radius
PKG_GROUPS=		${RADIUS_USER}
PKG_USERS=		${RADIUS_USER}:${RADIUS_GROUP}
PKG_GROUPS_VARS=	RADIUS_GROUP
PKG_USERS_VARS=		RADIUS_USER
OWN_DIRS_PERMS+=	${VARBASE}/run/radiusd \
			${RADIUS_USER} ${RADIUS_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/log/radiusd \
			${RADIUS_USER} ${RADIUS_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/log/radiusd/radacct \
			${RADIUS_USER} ${RADIUS_GROUP} 0750

RADVER=			1.1.8
EGDIR=			${PREFIX}/share/examples/freeradius

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7

CONFIGURE_ARGS+=	--with-logdir=${VARBASE}/log/radiusd
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--disable-ltdl-install
CONFIGURE_ARGS+=	--with-ltdl-lib=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-ltdl-include=${PREFIX}/include
CONFIGURE_ARGS+=	--without-rlm_ippool
CONFIGURE_ARGS+=	--without-rlm_smb
CONFIGURE_ARGS+=	--without-rlm_sql_iodbc
CONFIGURE_ARGS+=	--without-rlm_sql_oracle
CONFIGURE_ARGS+=	--without-rlm_sql_unixodbc
CONFIGURE_ARGS+=	--quiet
#CONFIGURE_ARGS+=	--without-rlm_eap_peap
#CONFIGURE_ARGS+=	--without-rlm_eap_sim
#CONFIGURE_ARGS+=	--without-rlm_eap_tls
#CONFIGURE_ARGS+=	--without-rlm_eap_ttls

REPLACE_PERL=		scripts/radsqlrelay

SUBST_CLASSES+=		make
SUBST_STAGE.make=	post-patch
SUBST_FILES.make=	src/modules/rlm_mschap/Makefile \
			src/modules/rlm_sql/drivers/rlm_sql_postgresql/Makefile.in
SUBST_SED.make=	-e "s|RLM_LDFLAGS	=|RLM_LDFLAGS 	= \
				../../../src/lib/libradius.la|g"
SUBST_SED.make+=	-e "s|RLM_SQL_LIBS	=|RLM_SQL_LIBS	= \
				-L${PREFIX}/lib|g"
SUBST_MESSAGE.make=	Fixing Makefiles.

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	raddb/radiusd.conf.in
SUBST_SED.config=	-e "s|@@RADIUS_USER@@|${RADIUS_USER}|g"
SUBST_SED.config+=	-e "s|@@RADIUS_GROUP@@|${RADIUS_GROUP}|g"
SUBST_MESSAGE.config=	Fixing configuration files.

.include "options.mk"

EGFILES=	acct_users attrs certs/demoCA/index.txt.old \
		certs/demoCA/cacert.pem certs/demoCA/index.txt \
		certs/demoCA/serial.old certs/demoCA/serial \
		certs/newcert.pem certs/README certs/dh \
		certs/cert-clt.der certs/cert-clt.p12 certs/cert-clt.pem \
		certs/cert-srv.der certs/cert-srv.p12 certs/cert-srv.pem \
		certs/newreq.pem certs/random certs/root.der certs/root.p12 \
		certs/root.pem clients clients.conf dictionary.in eap.conf \
		experimental.conf hints huntgroups ldap.attrmap mssql.conf \
		naslist naspasswd oraclesql.conf pgsql-voip.conf \
		postgresql.conf preproxy_users proxy.conf \
		realms snmp.conf sql.conf users radiusd.conf dictionary \
		otp.conf sqlippool.conf

.for f in ${EGFILES}
CONF_FILES_PERMS+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f} \
			${RADIUS_USER} ${RADIUS_GROUP} 0640
.endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--without-threads
.endif

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "pth"
.include "../../devel/pthread-sem/buildlink3.mk"
SUBST_SED.make+=	-e 's|@ldap_ldflags@|@ldap_ldflags@ \
			${PTHREAD_LDFLAGS:M*:Q} ${PTHREAD_LIBS:M*:Q} -lsemaphore|g'
.endif

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native"
SUBST_SED.make+=	-e 's|@ldap_ldflags@|@ldap_ldflags@ \
			${PTHREAD_LDFLAGS:M*:Q} ${PTHREAD_LIBS:M*:Q}|g'
.endif

.if ${MACHINE_ARCH} == "amd64"
CFLAGS+= -fPIC
.endif

post-build:
	${CP} ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC
	${CP} ${PKGDIR}/MESSAGE ${WRKDIR}/.MESSAGE_SRC
.if !empty(PKG_OPTIONS:Mpam)
	${CP} ${PKGDIR}/MESSAGE.pam ${WRKDIR}/.MESSAGE_SRC.pam
.endif

INSTALLATION_DIRS+=	${EGDIR}/certs/demoCA
INSTALL_ENV+=		R=${DESTDIR}
MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/certs ${RADIUS_USER} ${RADIUS_GROUP} 0750
MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/certs/demoCA ${RADIUS_USER} ${RADIUS_GROUP} 0750

post-install:
.for f in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/raddb/${f} ${DESTDIR}${EGDIR}/${f}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/src/modules/rlm_perl/example.pl ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
