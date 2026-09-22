# $NetBSD: options.mk,v 1.5 2026/09/22 16:49:50 abs Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.unifi
PKG_OPTIONS_GROUP.mongodb=	mongodb4 mongodb5 mongodb6
PKG_OPTIONS_REQUIRED_GROUPS=	mongodb
PKG_SUGGESTED_OPTIONS=		mongodb4

.include "../../mk/bsd.options.mk"

# Mongodb can upgrade *one* major version 4.4 -> 5, 5 -> 6 etc
# otherwise a backup/restore is needed

.if !empty(PKG_OPTIONS:Mmongodb4)
DEPENDS+=		mongodb>=4.0<5:../../databases/mongodb4
.endif

# If upgrading from 4.4 check featureCompatibilityVersion has been set, e.g.:
# - [Ensure unifi is running, and take a database backup from the UI]
# - [If the system started with 4.2 or an earlier version, set FCV]
#   mongo 127.0.0.1:27117
#   db.adminCommand( { setFeatureCompatibilityVersion: "4.4" } )
#   exit
# - /etc/rc.d/unifi stop
# - mongo 127.0.0.1:27117
#   db.adminCommand( { shutdown: 1 });
#   exit
# - [Upgrade mongdb package from 4.4 to 5]
# - /etc/rc.d/unifi start
#   [Verify unifi is running without issues]
# - mongo 127.0.0.1:27117
#   db.adminCommand( { setFeatureCompatibilityVersion: "5.0" } )
#   exit
#
# https://www.mongodb.com/docs/v5.0/release-notes/5.0-upgrade-standalone/
#
.if !empty(PKG_OPTIONS:Mmongodb5)
DEPENDS+=		mongodb>=5.0<6:../../databases/mongodb5
.endif

.if !empty(PKG_OPTIONS:Mmongodb6)
DEPENDS+=		mongodb>=6.0:../../databases/mongodb
.endif
