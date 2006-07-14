# $NetBSD: Makefile,v 1.51 2006/07/14 22:10:01 adrianp Exp $

DISTNAME=	freeradius-1.1.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/ \
		ftp://ftp.Awfulhak.org/pub/radius/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.freeradius.org/
COMMENT=	Free RADIUS server implementation

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=		radiusd-cistron-[0-9]*
USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		YES
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
FILES_SUBST+=		ROOT_USER=${ROOT_USER:Q}
FILES_SUBST+=		ROOT_GROUP=${ROOT_GROUP:Q}
USE_OLD_DES_API=	YES

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7

USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--with-logdir=${VARBASE}/log
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR:Q}
CONFIGURE_ARGS+=	--disable-ltdl-install
CONFIGURE_ARGS+=	--with-ltdl-lib=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-ltdl-include=${PREFIX}/include
CONFIGURE_ARGS+=        --without-rlm_ippool
CONFIGURE_ARGS+=        --without-rlm_smb
CONFIGURE_ARGS+=	--without-rlm_pam
CONFIGURE_ARGS+=	--without-rlm_sql_iodbc
CONFIGURE_ARGS+=	--without-rlm_sql_oracle
CONFIGURE_ARGS+=	--without-rlm_sql_unixodbc
#CONFIGURE_ARGS+=	--without-rlm_eap_peap
#CONFIGURE_ARGS+=	--without-rlm_eap_sim
#CONFIGURE_ARGS+=	--without-rlm_eap_tls
#CONFIGURE_ARGS+=	--without-rlm_eap_ttls

REPLACE_PERL=		scripts/radsqlrelay

SUBST_CLASSES=		make
SUBST_STAGE.make=	post-patch
SUBST_FILES.make=	src/modules/rlm_mschap/Makefile \
			src/modules/rlm_sql/drivers/rlm_sql_postgresql/Makefile.in
SUBST_SED.make= 	-e "s|RLM_LDFLAGS	=|RLM_LDFLAGS 	= \
				-L../../../src/lib/.libs/ -lradius|g"
SUBST_SED.make+=	-e "s|RLM_SQL_LIBS	=|RLM_SQL_LIBS	= \
				-L${PREFIX}/lib|g"
SUBST_MESSAGE.make=	Fixing Makefiles.

.include "options.mk"

RCD_SCRIPTS=		radiusd

OWN_DIRS=		${VARBASE}/run/radiusd

PKG_SYSCONFSUBDIR=	raddb
EGDIR=			${PREFIX}/share/examples/freeradius

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
		otp.conf otppasswd.sample

.for f in ${EGFILES}
CONF_FILES+= 	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--without-threads
.endif

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "pth"
.include "../../devel/pthread-sem/buildlink3.mk"
SUBST_SED.make+= 	-e 's|@ldap_ldflags@|@ldap_ldflags@ \
			${PTHREAD_LDFLAGS:Q} ${PTHREAD_LIBS:Q} -lsemaphore|g'
.endif

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native"
SUBST_SED.make+= 	-e 's|@ldap_ldflags@|@ldap_ldflags@ \
			${PTHREAD_LDFLAGS:Q} ${PTHREAD_LIBS:Q}|g'
.endif

.if ${OPSYS} == "DragonFly"
.endif

.if ${MACHINE_ARCH} == "amd64"
CFLAGS+= -fPIC
.endif

post-build:
	${CP} ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${EGDIR}/certs
	${INSTALL_DATA_DIR} ${EGDIR}/certs/demoCA
.for f in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/raddb/${f} ${EGDIR}/${f}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/src/modules/rlm_perl/example.pl ${EGDIR}
	${MKDIR} ${PKG_SYSCONFDIR}/certs
	${MKDIR} ${PKG_SYSCONFDIR}/certs/demoCA

.include "../../mk/bsd.pkg.mk"
