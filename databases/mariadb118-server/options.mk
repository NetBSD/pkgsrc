# $NetBSD: options.mk,v 1.1 2025/06/07 08:58:43 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql-server

PKG_SUPPORTED_OPTIONS+=	auth-pam embedded-server lzo lz4 oqgraph
PKG_SUPPORTED_OPTIONS+=	rocksdb snappy ssl zstd

.include "../../mk/bsd.fast.prefs.mk"

PKG_SUGGESTED_OPTIONS=	ssl

# auth_pam is not built on Solaris < 11.2 due to lack of getgrouplist
# but will work on illumos
.if ${OS_VARIANT} != "Solaris"
PKG_SUGGESTED_OPTIONS+=	auth-pam
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		embedded
.if !empty(PKG_OPTIONS:Membedded-server)
CMAKE_CONFIGURE_ARGS+=	-DWITH_EMBEDDED_SERVER=ON
PRINT_PLIST_AWK+=	/embedded/ { print "$${PLIST.embedded}" $$0; next }
PRINT_PLIST_AWK+=	/test-connect-t/ { print "$${PLIST.embedded}" $$0; next }
PRINT_PLIST_AWK+=	/libmysqld/ { print "$${PLIST.embedded}" $$0; next }
PRINT_PLIST_AWK+=	/libmariadbd/ { print "$${PLIST.embedded}" $$0; next }
PLIST.embedded=		yes
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_EMBEDDED_SERVER=OFF
.endif

.if !empty(PKG_OPTIONS:Mlzo)
.include "../../archivers/lzo/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DWITH_INNODB_LZO=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_INNODB_LZO=OFF
.endif

.if !empty(PKG_OPTIONS:Mlz4)
.include "../../archivers/lz4/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DGRN_WITH_LZ4=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_INNODB_LZ4=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_ROCKSDB_LZ4=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DGRN_WITH_LZ4=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_INNODB_LZ4=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_ROCKSDB_LZ4=OFF
.endif

PLIST_VARS+=	oqgraph
.if !empty(PKG_OPTIONS:Moqgraph)
CMAKE_CONFIGURE_ARGS+=	-DPLUGIN_OQGRAPH=YES
PLIST.oqgraph=		yes
PRINT_PLIST_AWK+=	/ha_oqgraph/ { print "$${PLIST.oqgraph}" $$0; next }
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libjudy/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DPLUGIN_OQGRAPH=NO
.endif

PLIST_VARS+=		rocksdb
.if !empty(PKG_OPTIONS:Mrocksdb)
.include "../../lang/python/application.mk"
PLIST.rocksdb=		yes
PRINT_PLIST_AWK+=	/ldb/ { print "$${PLIST.rocksdb}" $$0; next }
PRINT_PLIST_AWK+=	/ldb.1/ { print "$${PLIST.rocksdb}" $$0; next }
PRINT_PLIST_AWK+=	/ha_rocksdb/ { print "$${PLIST.rocksdb}" $$0; next }
PRINT_PLIST_AWK+=	/myrocks/ { print "$${PLIST.rocksdb}" $$0; next }
PRINT_PLIST_AWK+=	/sst_dump/ { print "$${PLIST.rocksdb}" $$0; next }
CMAKE_CONFIGURE_ARGS+=	-DWITHOUT_ROCKSDB_STORAGE_ENGINE=OFF
CMAKE_CONFIGURE_ARGS+=	-DPYTHON_SHEBANG=${PYTHONBIN}
.else
CMAKE_CONFIGURE_ARGS+=	-DWITHOUT_ROCKSDB_STORAGE_ENGINE=ON
.endif

.if !empty(PKG_OPTIONS:Msnappy)
.include "../../devel/snappy/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DWITH_INNODB_SNAPPY=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_ROCKSDB_snappy=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_INNODB_SNAPPY=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_ROCKSDB_snappy=OFF
.endif

# Enable OpenSSL support
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DWITH_SSL=system
LDFLAGS+=	-lcrypto -lssl
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_SSL=no
.endif

.if !empty(PKG_OPTIONS:Mzstd)
.include "../../archivers/zstd/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DWITH_ROCKSDB_zstd=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_ROCKSDB_zstd=OFF
.endif

PLIST_VARS+=		auth_pam
.if !empty(PKG_OPTIONS:Mauth-pam)
CMAKE_CONFIGURE_ARGS+=	-DPLUGIN_AUTH_PAM=YES
CMAKE_CONFIGURE_ARGS+=	-DPLUGIN_AUTH_PAM_V1=YES
PLIST.auth_pam=		yes
PRINT_PLIST_AWK+=	/auth_pam/ { print "$${PLIST.auth_pam}" $$0; next }
PRINT_PLIST_AWK+=	/user_map/ { print "$${PLIST.auth_pam}" $$0; next }
.else
CMAKE_CONFIGURE_ARGS+=	-DPLUGIN_AUTH_PAM=NO
CMAKE_CONFIGURE_ARGS+=	-DPLUGIN_AUTH_PAM_V1=NO
.endif
