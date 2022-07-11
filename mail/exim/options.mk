# $NetBSD: options.mk,v 1.26 2022/07/11 10:52:29 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.exim
PKG_SUPPORTED_OPTIONS=	exim-appendfile-maildir exim-appendfile-mailstore
PKG_SUPPORTED_OPTIONS+=	exim-appendfile-mbx exim-auth-dovecot exim-build-eximon
PKG_SUPPORTED_OPTIONS+=	exim-content-scan exim-lookup-cdb exim-lookup-dnsdb
PKG_SUPPORTED_OPTIONS+=	exim-lookup-dsearch exim-lookup-ldap exim-lookup-mysql
PKG_SUPPORTED_OPTIONS+=	exim-lookup-pgsql exim-lookup-redis exim-lookup-sqlite
PKG_SUPPORTED_OPTIONS+=	exim-lookup-whoson exim-old-demime exim-router-iplookup
PKG_SUPPORTED_OPTIONS+=	exim-tcp-wrappers exim-tls exim-transport-lmtp gdbm
PKG_SUPPORTED_OPTIONS+=	inet6 opendmarc saslauthd spf readline

PKG_SUGGESTED_OPTIONS=	exim-appendfile-maildir exim-appendfile-mailstore
PKG_SUGGESTED_OPTIONS+=	exim-appendfile-mbx exim-content-scan
PKG_SUGGESTED_OPTIONS+=	exim-lookup-dsearch exim-old-demime exim-tcp-wrappers
PKG_SUGGESTED_OPTIONS+=	exim-tls inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mexim-appendfile-maildir)
LOCAL_MAKEFILE_OPTIONS+=	SUPPORT_MAILDIR=yes
.endif

.if !empty(PKG_OPTIONS:Mexim-appendfile-mailstore)
LOCAL_MAKEFILE_OPTIONS+=	SUPPORT_MAILSTORE=yes
.endif

.if !empty(PKG_OPTIONS:Mexim-auth-dovecot)
LOCAL_MAKEFILE_OPTIONS+=	AUTH_DOVECOT=yes
.endif

.if !empty(PKG_OPTIONS:Mexim-appendfile-mbx)
LOCAL_MAKEFILE_OPTIONS+=	SUPPORT_MBX=yes
.endif

.if !empty(PKG_OPTIONS:Mexim-build-eximon)
LOCAL_MAKEFILE_OPTIONS+=EXIM_MONITOR=eximon.bin
LOCAL_MAKEFILE_OPTIONS+=X11=${X11BASE}
PLIST_SRC+=${PKGDIR}/PLIST.eximon
.  include "../../x11/libXaw/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mexim-content-scan)
LOCAL_MAKEFILE_OPTIONS+=	WITH_CONTENT_SCAN=YES
.endif

.if !empty(PKG_OPTIONS:Mexim-lookup-cdb)
LOCAL_MAKEFILE_OPTIONS+= LOOKUP_CDB=YES
DEPENDS+=	cdb-[0-9]*:../../databases/cdb
.endif

.if !empty(PKG_OPTIONS:Mexim-lookup-dnsdb)
LOCAL_MAKEFILE_OPTIONS+=	LOOKUP_DNSDB=YES
.endif

.if !empty(PKG_OPTIONS:Mexim-lookup-dsearch)
LOCAL_MAKEFILE_OPTIONS+=	LOOKUP_DSEARCH=YES
.endif

.if !empty(PKG_OPTIONS:Mexim-lookup-ldap)
LOCAL_MAKEFILE_OPTIONS+=LOOKUP_LDAP=YES
LOCAL_MAKEFILE_OPTIONS+=LDAP_LIB_TYPE=OPENLDAP2
LOOKUP_LIBS+=-lldap -llber
.  include "../../databases/openldap-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mexim-lookup-mysql)
LOCAL_MAKEFILE_OPTIONS+=LOOKUP_MYSQL=YES
LOOKUP_LIBS+=-lmysqlclient
.  include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mexim-lookup-pgsql)
LOCAL_MAKEFILE_OPTIONS+=LOOKUP_PGSQL=YES
LOOKUP_LIBS+=-lpq
.  include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mexim-lookup-redis)
LOCAL_MAKEFILE_OPTIONS+=LOOKUP_REDIS=YES
LOOKUP_LIBS+=-lhiredis
.  include "../../databases/hiredis/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mexim-lookup-sqlite)
LOCAL_MAKEFILE_OPTIONS+=LOOKUP_SQLITE=YES
LOOKUP_LIBS+=-lsqlite3
.  include "../../databases/sqlite3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mexim-lookup-whoson)
LOCAL_MAKEFILE_OPTIONS+=LOOKUP_WHOSON=YES
LOOKUP_LIBS+=-lwhoson
.  include "../../net/whoson/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mexim-old-demime)
LOCAL_MAKEFILE_OPTIONS+=	WITH_OLD_DEMIME=YES
.endif

.if !empty(PKG_OPTIONS:Mexim-router-iplookup)
LOCAL_MAKEFILE_OPTIONS+=	ROUTER_IPLOOKUP=yes
.endif

.if !empty(PKG_OPTIONS:Mexim-tcp-wrappers)
LOCAL_MAKEFILE_OPTIONS+=USE_TCP_WRAPPERS=yes
LOOKUP_LIBS+=-lwrap
.  include "../../security/tcp_wrappers/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mexim-tls)
LOCAL_MAKEFILE_OPTIONS+=SUPPORT_TLS=yes
LOCAL_MAKEFILE_OPTIONS+=USE_OPENSSL=yes
LOOKUP_LIBS+=-lssl -lcrypto
.  include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mexim-transport-lmtp)
LOCAL_MAKEFILE_OPTIONS+=	TRANSPORT_LMTP=yes
.endif

.if !empty(PKG_OPTIONS:Minet6)
LOCAL_MAKEFILE_OPTIONS+=	HAVE_IPV6=YES
.else
LOCAL_MAKEFILE_OPTIONS+=	HAVE_IPV6=NO
.endif

.if !empty(PKG_OPTIONS:Mopendmarc)
LOCAL_MAKEFILE_OPTIONS+=EXPERIMENTAL_DMARC=yes
LOOKUP_LIBS+=		-lopendmarc
.  include "../../mail/opendmarc/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgdbm)
.  include "../../databases/gdbm/buildlink3.mk"
EXIM_USE_DB_CONFIG=	USE_GDBM=yes
EXIM_DBMLIB=		DBMLIB=${LDFLAGS} -lgdbm
EXIM_INCLUDE=		-I${PREFIX}/include
.else # use Berkeley DB as defined by BDB_DEFAULT and BDB_ACCEPTED
BDB_ACCEPTED?=db2 db3 db4 db5 db6
.  include "../../mk/bdb.buildlink3.mk"
EXIM_USE_DB_CONFIG=	USE_DB=yes	# the default
EXIM_DBMLIB=		DBMLIB=${LDFLAGS} ${BDB_LIBS}
EXIM_INCLUDE=		-I${PREFIX}/${BUILDLINK_INCDIRS.${BDB_TYPE}}
.endif

.if !empty(PKG_OPTIONS:Msaslauthd)
LOCAL_MAKEFILE_OPTIONS+=AUTH_CYRUS_SASL=YES
LOCAL_MAKEFILE_OPTIONS+=CYRUS_SASLAUTHD_SOCKET=/var/state/saslauthd/mux
LOOKUP_LIBS+=${COMPILER_RPATH_FLAG}${LOCALBASE}/${BUILDLINK_LIBDIRS.cyrus-sasl} -L${LOCALBASE}/${BUILDLINK_LIBDIRS.cyrus-sasl} -lsasl2
.  include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mspf)
LOCAL_MAKEFILE_OPTIONS+=SUPPORT_SPF=yes
LOOKUP_LIBS+=		-lspf2
.  include "../../mail/libspf2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mreadline)
LOCAL_MAKEFILE_OPTIONS+=USE_READLINE=yes
LOOKUP_LIBS+=		-lreadline
.  include "../../devel/readline/buildlink3.mk"
.endif
