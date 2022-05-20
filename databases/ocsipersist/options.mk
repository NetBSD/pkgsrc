# $NetBSD: options.mk,v 1.1 2022/05/20 06:47:28 jaapb Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ocsipersist
PKG_OPTIONS_NONEMPTY_SETS=	database
PKG_OPTIONS_SET.database=	sqlite gdbm pgsql
PKG_SUGGESTED_OPTIONS=		gdbm
PLIST_VARS=			sqlite dbm pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=		ocaml-sqlite3>=0.23.0:../../databases/ocaml-sqlite3
.include "../../devel/ocaml-lwt_log/buildlink3.mk"
.include "../../textproc/ocaml-xml-light/buildlink3.mk"
DUNE_BUILD_PACKAGES+=	ocsipersist-sqlite
PLIST.sqlite=		yes
.endif

.if !empty(PKG_OPTIONS:Mgdbm)
.include "../../devel/ocaml-lwt_log/buildlink3.mk"
.include "../../textproc/ocaml-xml-light/buildlink3.mk"
DUNE_BUILD_PACKAGES+=	ocsipersist-dbm
PLIST.dbm=		yes
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../databases/pgocaml/buildlink3.mk"
.include "../../devel/ocaml-lwt_log/buildlink3.mk"
.include "../../textproc/ocaml-xml-light/buildlink3.mk"
DUNE_BUILD_PACKAGES+=	ocsipersist-pgsql
PLIST.pgsql=		yes
.endif
