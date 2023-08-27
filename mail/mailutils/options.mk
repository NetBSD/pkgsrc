# $NetBSD: options.mk,v 1.2 2023/08/27 11:56:26 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mailutils

PKG_OPTIONS_REQUIRED_GROUPS=	dbm
PKG_OPTIONS_GROUP.dbm=		ndbm bdb gdbm

PKG_SUPPORTED_OPTIONS+=	bdb emacs fribidi gdbm gnutls gsasl gssapi
PKG_SUPPORTED_OPTIONS+=	guile ldap mysql ndbm nls pgsql python
PKG_SUGGESTED_OPTIONS=	gnutls gsasl gssapi

.if exists(/usr/include/ndbm.h) && (${OPSYS:M*BSD} != "" || ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly")
PKG_SUGGESTED_OPTIONS+=	ndbm
.elif exists(/usr/include/gdbm.h) || ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	gdbm
.else
PKG_SUGGESTED_OPTIONS+=	bdb
.endif

PLIST_VARS+=		emacs guile nls python

.include "../../mk/bsd.options.mk"

# UNIX databases
## New DBM
.if !empty(PKG_OPTIONS:Mndbm)
CONFIGURE_ARGS+=	--with-ndbm
.else
CONFIGURE_ARGS+=    	--without-ndbm
.endif
## Berkeley DB
.if !empty(PKG_OPTIONS:Mbdb)
BDB_ACCEPTED=		db3 db4 db5 db6
BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.  include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=        --with-berkeley-db=${BDB_TYPE}
.else
CONFIGURE_ARGS+=	--without-berkeley-db
.endif
# GDBM
.if !empty(PKG_OPTIONS:Mgdbm)
.  include "../../databases/gdbm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gdbm
.else
CONFIGURE_ARGS+=    	--without-gdbm
.endif

# Native Language Support
.if	!empty(PKG_OPTIONS:Mnls)
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt msgmerge xgettext
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext}
CONFIGURE_ENV+=		gt_cv_func_gnugettext_libintl=yes
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--without-libintl-prefix
.endif

# GSSAPI (Kerberos5) authentication
.if !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=       --with-gssapi==${KRB5BASE:Q}
GSSIMPL.heimdal=	Heimdal
GSSIMPL.mit-krb5=	MIT
CONFIGURE_ENV+=		GSSAPI_IMPL=${GSSIMPL.${KRB5_TYPE}}
.else
CONFIGURE_ARGS+=       --without-gssapi
.endif

# GnuTLS
.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=    --with-gnutls
.else
CONFIGURE_ARGS+=    --without-gnutls
.endif

# GNUsasl
.if !empty(PKG_OPTIONS:Mgsasl)
.  include "../../security/gsasl/buildlink3.mk"
CONFIGURE_ARGS+=    --with-gsasl
.else
CONFIGURE_ARGS+=    --without-gsasl
.endif

# EmacsLisp
.if !empty(PKG_OPTIONS:Memacs)
.include "../../editors/emacs/modules.mk"
BUILDLINK_API_DEPENDS.emacs+=	${_EMACS_REQD}
BUILDLINK_PKGSRCDIR.emacs?=	${_EMACS_PKGDIR}
CONFIGURE_ENV+=			ac_cv_prog_EMACS=${EMACS_BIN:Q}
PKGSRC_MAKE_ENV+=		EMACS=${EMACS:Q}
CONFIGURE_ARGS+=    		--with-lispdir=${EMACS_LISPPREFIX:Q}
PLIST.emacs=			yes
.else
CONFIGURE_ENV+=			ac_cv_prog_EMACS=no
PKGSRC_MAKE_ENV+=		EMACS=${FALSE:Q}
.endif

# MySQL
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql
LDFLAGS+=		${BUILDLINK_LDFLAGS.mysql-client}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

# PostgreSQL
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-postgres
LDFLAGS+=		${BUILDLINK_LDFLAGS.postgresql-lib}
.else
CONFIGURE_ARGS+=    	--without-postgres
.endif

# LDAP
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap
LDFLAGS+=		${BUILDLINK_LDFLAGS.openldap-client}
.else
CONFIGURE_ARGS+=    	--without-ldap
.endif

# GNU FriBidi
.if !empty(PKG_OPTIONS:Mfribidi)
.  include "../../converters/fribidi/buildlink3.mk"
CONFIGURE_ARGS+=    --with-fribidi
.else
CONFIGURE_ARGS+=    --without-fribidi
.endif

# GNU Guile
.if !empty(PKG_OPTIONS:Mguile)
USE_TOOLS+=		makeinfo pkg-config
.  include "../../lang/guile30/buildlink3.mk"
CONFIGURE_ARGS+=    	--with-guile
PLIST.guile=      	yes
.else
CONFIGURE_ARGS+=	--without-guile
.endif

# Python
.if !empty(PKG_OPTIONS:Mpython)
PYTHON_VERSIONS_INCOMPATIBLE=	  27
.include "../../lang/python/application.mk"
CONFIGURE_ENV+=	PYTHON_CONFIG=${PREFIX}/bin/python${PYVERSSUFFIX}-config
CONFIGURE_ARGS+=	--enable-python
PLIST.python=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}
.else
CONFIGURE_ARGS+=	--disable-python
.endif

## C++ support is marked as experimental.
#.if !empty(PKG_OPTIONS:Mc++)
#CONFIGURE_ARGS+=	--enable-experimental
#CONFIGURE_ARGS+=	--enable-cxx
#.endif c
