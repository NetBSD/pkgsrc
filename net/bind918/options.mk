# $NetBSD: options.mk,v 1.1 2022/12/11 01:57:55 sekiya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bind
PKG_SUPPORTED_OPTIONS=	bind-dig-sigchase bind-xml-statistics-server
PKG_SUPPORTED_OPTIONS+=	bind-json-statistics-server blacklist blocklist
PKG_SUPPORTED_OPTIONS+=	threads readline lmdb mysql pgsql ldap dlz-filesystem
PKG_SUPPORTED_OPTIONS+=	geoip tuning dnstap
PKG_SUGGESTED_OPTIONS+=	readline

PLIST_VARS+=	dnstap lmdb

PTHREAD_OPTS+=		native
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none") || \
	!empty(MACHINE_PLATFORM:MNetBSD-*-vax) || \
	!empty(MACHINE_PLATFORM:MNetBSD-*-sparc) || \
	!empty(MACHINE_PLATFORM:MNetBSD-*-sparc64) || \
	!empty(MACHINE_PLATFORM:MNetBSD-*-m68k)
# don't touch PKG_SUGGESTED_OPTIONS
.else
PKG_SUGGESTED_OPTIONS+=	threads
.endif

.if ${OPSYS} == "NetBSD"
.  if !empty(PKG_OPTIONS:Mblacklist)
.    if exists(/usr/include/blacklist.h)
PKG_SUGGESTED_OPTIONS+=	blacklist
.    elif !empty(PKG_OPTIONS:Mblocklist) && exists(/usr/include/blocklist.h)
PKG_SUGGESTED_OPTIONS+=	blocklist
.    endif
.  endif
.endif

.include "../../mk/bsd.options.mk"

###
### The mysql pgsql ldap dlz-filesystem options are all for BIND
### DLZ (Dynamically Loadable Zones) functionality
###
### NOTE: bdb is excluded on purpose as pkgsrc does not contain
###       a bdb v4.1 or 4.2 package which is what BIND needs.
###       The majority of these are compile tested only
###

.if !empty(PKG_OPTIONS:Mlmdb)
.include "../../databases/lmdb/buildlink3.mk"
CONFIGURE_ARGS+=	--with-lmdb=${PREFIX}
PLIST.lmdb=		yes
.else
CONFIGURE_ARGS+=	--with-lmdb=no
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-dlz-mysql=${BUILDLINK_PREFIX.mysql-client}
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-dlz-postgres=${BUILDLINK_PREFIX.${PGSQL_TYPE}}
CONFIGURE_ENV+=		ac_cv_path_PG_CONFIG=${PREFIX}/bin/pg_config
.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-dlz-ldap=${BUILDLINK_PREFIX.openldap-client}
.endif

.if !empty(PKG_OPTIONS:Mdlz-filesystem)
CONFIGURE_ARGS+=	--with-dlz-filesystem
.endif

.if !empty(PKG_OPTIONS:Mblacklist)
CONFIGURE_ARGS+=	--with-blacklist=yes
.else
CONFIGURE_ARGS+=	--with-blacklist=no
.endif

.if !empty(PKG_OPTIONS:Mblocklist)
CONFIGURE_ARGS+=	--with-blocklist=yes
.else
CONFIGURE_ARGS+=	--with-blocklist=no
.endif

.if !empty(PKG_OPTIONS:Mgeoip)
CONFIGURE_ARGS+=	--with-geoip=${PREFIX}
LDFLAGS+=		-lGeoIP
.include "../../net/GeoIP/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtuning)
CONFIGURE_ARGS+=	--with-tuning=large
.endif

.if !empty(PKG_OPTIONS:Mdnstap)
CONFIGURE_ARGS+=	--enable-dnstap
PLIST.dnstap=		yes
.include "../../net/fstrm/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
.endif

###
### The statistics server in bind99 and later needs libxml2
###
.if !empty(PKG_OPTIONS:Mbind-xml-statistics-server)
.include "../../textproc/libxml2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libxml2
LDFLAGS+=		-lxml2
.else
CONFIGURE_ARGS+=	--without-libxml2
.endif

###
### The statistics server in bind911 and later supports json
###
.if !empty(PKG_OPTIONS:Mbind-json-statistics-server)
.include "../../textproc/json-c/buildlink3.mk"
CONFIGURE_ARGS+=	--with-json-c=yes
.else
CONFIGURE_ARGS+=	--with-json-c=no
.endif

###
### pthreads support (also see magic above)
###
.if !empty(PKG_OPTIONS:Mthreads)
PTHREAD_AUTO_VARS=	yes
.endif

###
### readline support in dig(1) and nsupdate(1).
###
.if !empty(PKG_OPTIONS:Mreadline)
.include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--with-readline
.else
CONFIGURE_ARGS+=	--without-readline
.endif

###
### dig(1) option +sigchase for DNSSEC signature chasing
###
.if !empty(PKG_OPTIONS:Mbind-dig-sigchase)
# If anything else needs to add entries to STD_CDEFINES, this will need
# to be changed so that the two can cooperate.
CONFIGURE_ENV+=		STD_CDEFINES=-DDIG_SIGCHASE=1
.endif
