# $NetBSD: options.mk,v 1.6 2024/08/25 06:18:29 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql-server

PKG_SUPPORTED_OPTIONS+=	columnstore embedded-server lzo lz4 oqgraph rocksdb
PKG_SUPPORTED_OPTIONS+=	snappy ssl zstd

.include "../../mk/bsd.fast.prefs.mk"

PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcolumnstore)
.include "../../devel/boost-headers/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DPLUGIN_COLUMNSTORE=YES
.else
CMAKE_CONFIGURE_ARGS+=	-DPLUGIN_COLUMNSTORE=NO
.endif

PLIST_VARS+=	embedded
.if !empty(PKG_OPTIONS:Membedded-server)
CMAKE_CONFIGURE_ARGS+=	-DWITH_EMBEDDED_SERVER=ON
PLIST.embedded=	yes
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
PLIST.oqgraph=	yes
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libjudy/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DPLUGIN_OQGRAPH=NO
.endif

PLIST_VARS+=	rocksdb
.if !empty(PKG_OPTIONS:Mrocksdb)
.include "../../lang/python/application.mk"
PLIST.rocksdb=	yes
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
