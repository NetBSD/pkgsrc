# $NetBSD: Makefile,v 1.24 2005/02/18 16:59:57 adrianp Exp $

DISTNAME=	freeradius-1.0.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/ \
		ftp://ftp.Awfulhak.org/pub/radius/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.freeradius.org/
COMMENT=	Free RADIUS server implementation

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=		radiusd-cistron*
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
USE_BUILDLINK3= 	YES
USE_PKGINSTALL=		YES
USE_PERL5=		YES
LIBTOOLIZE_PLIST=	NO
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
FILES_SUBST+=		ROOT_USER=${ROOT_USER}
FILES_SUBST+=		ROOT_GROUP=${ROOT_GROUP}

# This package currently breaks using our libtool.  It does not appear to use
# libtool properly/fully and as a result the daemon does not compile correctly.
#
#USE_LIBTOOL=		YES
#LIBTOOL_OVERRIDE=	libtool

CONFIGURE_ARGS+=	--with-logdir=${VARBASE}/log
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--disable-ltdl-install
CONFIGURE_ARGS+=	--with-ltdl-lib=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-ltdl-include=${PREFIX}/include
CONFIGURE_ARGS+=        --without-rlm_ippool
CONFIGURE_ARGS+=        --without-rlm_smb
CONFIGURE_ARGS+=	--without-rlm_krb5
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_pam
CONFIGURE_ARGS+=	--without-rlm_sql_iodbc
CONFIGURE_ARGS+=	--without-rlm_sql_mysql
CONFIGURE_ARGS+=	--without-rlm_sql_postgresql
CONFIGURE_ARGS+=	--without-rlm_sql_oracle
CONFIGURE_ARGS+=	--without-rlm_sql_unixodbc
CONFIGURE_ARGS+=	--without-snmp

SUBST_CLASSES=		make
SUBST_STAGE.make=	post-patch
SUBST_FILES.make=	src/modules/rlm_ldap/Makefile.in \
			src/modules/rlm_mschap/Makefile \
			src/modules/rlm_sql/drivers/rlm_sql_postgresql/Makefile.in
SUBST_SED.make= 	-e "s|RLM_LDFLAGS	=|RLM_LDFLAGS 	= \
				-L../../../src/lib/.libs/ -lradius|g" \
			-e "s|RLM_SQL_LIBS	=|RLM_SQL_LIBS	= \
				-L${PREFIX}/lib|g"
SUBST_MESSAGE.make=	"Fixing Makefiles."

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
		postgresql.conf preproxy_users proxy.conf radiusd.conf.in \
		realms snmp.conf sql.conf users x99.conf x99passwd.sample \
		radiusd.conf dictionary

.for f in ${EGFILES}
CONF_FILES+= 	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
.undef f

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--without-threads
.endif

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "pth"
.include "../../devel/pthread-sem/buildlink3.mk"
SUBST_SED.make+= 	-e "s|@ldap_ldflags@|@ldap_ldflags@ \
				-lpthread -lsemaphore|g" 
.endif

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native"
SUBST_SED.make+= 	-e "s|@ldap_ldflags@|@ldap_ldflags@ \
				-lpthread|g" 
.endif

pre-build:
	cd ${WRKSRC} && ${LN} -s src/lib lib

post-build:
	@${CP} ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${EGDIR}/certs
	${INSTALL_DATA_DIR} ${EGDIR}/certs/demoCA

.	for f in ${EGFILES}
		${INSTALL_DATA} ${WRKSRC}/raddb/${f} ${EGDIR}/${f}
.	endfor
.	undef f

	@${MKDIR} ${PKG_SYSCONFDIR}/certs
	@${MKDIR} ${PKG_SYSCONFDIR}/certs/demoCA
	cd ${WRKSRC} && ${FIND} . -name .libs | ${XARGS} ${RM} -rf

.include "../../mk/bsd.pkg.mk"
