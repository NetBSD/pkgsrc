# $NetBSD: Makefile,v 1.4 2004/06/26 11:21:46 abs Exp $
#

DISTNAME=		jabberd-2.0s2
PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		http://www.jabberstudio.org/files/jabberd2/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://jabberd.jabberstudio.org/2/
COMMENT=		Instant messaging server (version 2)

CONFLICTS=		jabberd-[0-9]*:../../chat/jabberd

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

BUILDLINK_DEPENDS.openssl+=	openssl>=0.9.6b
BUILDLINK_TRANSFORM.db4=	-e "s,/db4/,/,g"

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	configure
SUBST_MESSAGE.path=	"Fixing configure script."
SUBST_SED.path=		-e "s,/usr/local,${PREFIX},g"			\
			-e "s,\$sysconfdir/jabberd,\$sysconfdir,g"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
#CONFIGURE_ARGS+=	--enable-debug

REPLACE_PERL=		tools/pipe-auth.pl

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	JABBERD_USER JABBERD_STATIC				\
		JABBERD_AUTH_METHOD JABBERD_STORAGE_METHOD		\
		JABBERD_LOGDIR JABBERD_DBDIR JABBERD_PIDDIR

# This specify the actual method which will be used for authenticate
# the users/accounts.
#
# JABBERD_AUTH_METHOD has 4 available options:
#
# db (by default)
# mysql (MySQL)
# openldap (OpenLDAP)
# pam (Pluggable Authentication Module)
# pgsql (PostgreSQL)

JABBERD_AUTH_METHOD?=		db
AUTHREG_MODS="anon pipe ${JABBERD_AUTH_METHOD}"

.if !empty(JABBERD_AUTH_METHOD:Mdb)
CONFIGURE_ARGS+=	--enable-authreg=${AUTHREG_MODS}
CONFIGURE_ARGS+=	--with-berkeley-db=${BUILDLINK_DIR}/include
.    include "../../databases/db4/buildlink3.mk"
.  elif !empty(JABBERD_AUTH_METHOD:Mopenldap)
CONFIGURE_ARGS+=	--enable-authreg=${AUTHREG_MODS}
CONFIGURE_ARGS+=	--with-openldap=${BUILDLINK_PREFIX.openldap}
.    include "../../databases/openldap/buildlink3.mk"
.  elif !empty(JABBERD_AUTH_METHOD:Mpgsql)
CONFIGURE_ARGS+=	--enable-authreg=${AUTHREG_MODS}
CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.postgresql-lib}
.    include "../../databases/postgresql-lib/buildlink3.mk"
.  elif !empty(JABBERD_AUTH_METHOD:Mmysql)
CONFIGURE_ARGS+=	--enable-authreg=${AUTHREG_MODS}
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-server}
.    include "../../databases/mysql-client/buildlink3.mk"
.  elif !empty(JABBERD_AUTH_METHOD:Mpam)
CONFIGURE_ARGS+=	--enable-authreg=${AUTHREG_MODS}
CONFIGURE_ARGS+=	--with-pam=${BUILDLINK_PREFIX.PAM}
.    include "../../security/PAM/buildlink3.mk"
.endif

# This specify the actual method which will be used to store the accounts
# and related information.
#
# JABBERD_STORAGE_METHOD has 3 available options:
#
# db (by default)
# mysql (MySQL)
# pgsql (PostgreSQL)

JABBERD_STORAGE_METHOD?=	db

.if !empty(JABBERD_STORAGE_METHOD:Mdb)
CONFIGURE_ARGS+=	--enable-storage=db
CONFIGURE_ARGS+=	--with-berkeley-db=${BUILDLINK_DIR}/include
.    include "../../databases/db4/buildlink3.mk"
.  elif !empty(JABBERD_STORAGE_METHOD:Mmysql)
CONFIGURE_ARGS+=	--enable-storage=mysql
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-server}
.    include "../../databases/mysql-client/buildlink3.mk"
.  elif !empty(JABBERD_STORAGE_METHOD:Mpgsql)
CONFIGURE_ARGS+=	--enable-storage=pgsql
CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.postgresql-lib}
.    include "../../databases/postgresql-lib/buildlink3.mk"
.endif

.if defined(JABBERD_STATIC) && !empty(JABBERD_STATIC:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-all-static
.endif

PKG_SYSCONFSUBDIR=	jabberd
RCD_SCRIPTS=		jabberd c2s sm resolver router s2s
JABBERD_USER?=		jabberd
JABBERD_GROUP?=		jabberd
FILES_SUBST+=		JABBERD_USER=${JABBERD_USER}
FILES_SUBST+=		JABBERD_GROUP=${JABBERD_GROUP}
FILES_SUBST+=		JABBERD_PIDDIR=${JABBERD_PIDDIR}
FILES_SUBST+=		JABBERD_LOGDIR=${JABBERD_LOGDIR}
PKG_GROUPS=             ${JABBERD_GROUP}
PKG_USERS=              ${JABBERD_USER}:${JABBERD_GROUP}

BINDIR=			${PREFIX}/bin
EGDIR=			${PREFIX}/share/examples/jabberd
SUPPORT_FILES=          ${EGDIR}/jabberd.cfg ${PKG_SYSCONFDIR}/jabberd.cfg

FILES=			c2s.xml resolver.xml router.xml			\
			router-users.xml s2s.xml sm.xml
DBFILES=		db-setup.mysql db-setup.pgsql

.for f in ${FILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
CONF_FILES+=		${EGDIR}/roster.xml ${PKG_SYSCONFDIR}/roster.xml
.undef f

# Directory to store the log files
JABBERD_LOGDIR?=	/var/log/jabberd
# Directory to store the database files
JABBERD_DBDIR?=		/var/db/jabberd
# Directory to store the pid files
JABBERD_PIDDIR?=	/var/run/jabberd

.for f in ${JABBERD_LOGDIR} ${JABBERD_DBDIR} ${JABBERD_PIDDIR}
OWN_DIRS_PERMS+=	${f} ${JABBERD_USER} ${JABBERD_GROUP} 770
.endfor
.undef f

post-extract:
.for f in jabberd.cfg ${FILES}
	@${MV} ${WRKSRC}/etc/${f}.dist.in ${WRKSRC}/etc/${f}.in
.endfor
.undef f

pre-configure:
.for f in ${FILES}
	@${SED}								\
		-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"		\
		-e "s|@PIDDIR@|${JABBERD_PIDDIR}|g"			\
		-e "s|@LOGDIR@|${JABBERD_LOGDIR}|g"			\
		-e "s|@SSLCERTS@|${SSLCERTS}|g"				\
		-e "s|@BINDIR@|${PREFIX}/bin|g"				\
		-e "s|@DBDIR@|${JABBERD_DBDIR}|g"			\
		${WRKSRC}/etc/${f}.in > ${WRKSRC}/etc/${f}
.endfor
.undef f
	@${SED}								\
		-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"		\
		-e "s|@BINDIR@|${PREFIX}/bin|g "			\
		${WRKSRC}/etc/jabberd.cfg.in > ${WRKSRC}/etc/jabberd.cfg

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/templates/roster.xml.dist.in	\
	    ${EGDIR}/roster.xml
	${INSTALL_SCRIPT} ${WRKSRC}/tools/pipe-auth.pl ${BINDIR}
.for f in ${DBFILES}
	${INSTALL_DATA} ${WRKSRC}/tools/${f} ${EGDIR}
.endfor
.undef f
.for f in jabberd.cfg ${FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${EGDIR}
.endfor
.undef f

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
