# $NetBSD: options.mk,v 1.2 2026/03/18 18:15:21 nia Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.cyrus-imapd
PKG_SUPPORTED_OPTIONS=	gssapi kerberos kerberos4 ldap pcre snmp
PKG_SUPPORTED_OPTIONS+=	mysql pgsql doc
PKG_SUGGESTED_OPTIONS=	pcre doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkerberos)
.  if empty(PKG_OPTIONS:Mgssapi)
PKG_OPTIONS+=	gssapi
.  endif
.endif

.if !empty(PKG_OPTIONS:Mkerberos4)
.  if exists(/usr/include/kerberosIV/krb.h)
PKG_USE_KERBEROS=	yes
CONFIGURE_ARGS+=	--with-krb=/usr
.  endif
.elif !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit
CONFIGURE_ENV+=		COMPILE_ET=${KRB5BASE}/bin/compile_et
.else
CONFIGURE_ARGS+=	--without-krb
CONFIGURE_ARGS+=	--disable-gssapi
CHECK_BUILTIN.heimdal:=		yes
.  include "../../security/heimdal/builtin.mk"
CHECK_BUILTIN.heimdal:=		no
CHECK_BUILTIN.mit-krb5:=	yes
.  include "../../security/mit-krb5/builtin.mk"
CHECK_BUILTIN.mit-krb5:=	no
.  if ( ${USE_BUILTIN.heimdal:tl} == yes || \
	${USE_BUILTIN.mit-krb5:tl} == yes) && \
        exists(/usr/bin/compile_et) && exists(/usr/include/krb5/com_err.h)
CPPFLAGS+=	-I/usr/include/krb5
CONFIGURE_ENV+=	COMPILE_ET=/usr/bin/compile_et
.  elif ${OPSYS} != "Linux" && \
	exists(/usr/bin/compile_et) && exists(/usr/include/com_err.h)
CONFIGURE_ENV+=	COMPILE_ET=/usr/bin/compile_et
.  else
CONFIGURE_ARGS+=	--with-com-err=yes
.  endif
.endif
.if !empty(CONFIGURE_ENV:MCOMPILE_ET=*)
post-configure:		generate-compile-et
.endif

generate-compile-et:
	${RUN}cd ${WRKSRC}/com_err/et;				\
	if ${TEST} ! -f Makefile -a  ! -f compile_et; then	\
		${SED} 	-e 's,@SED@,${SED},g'			\
			-e 's,@AWK@,${AWK},g'			\
			-e 's,@DIR@,${WRKSRC}/com_err/et,g'	\
			< compile_et.sh > compile_et;		\
		${CHMOD} +x compile_et;				\
	fi

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if !empty(PKG_OPTIONS:Msnmp)
.  include "../../net/net-snmp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-snmp=${BUILDLINK_PREFIX.net-snmp}
USE_TOOLS+=		perl:run
.else
CONFIGURE_ARGS+=	--without-snmp
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql=${PGSQL_PREFIX}
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if !empty(PKG_OPTIONS:Mpcre)
.  include "../../devel/pcre/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_TARGET+=		man
.include "../../lang/python/pyversion.mk"
PYTHON_FOR_BUILD_ONLY=	yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
CONFIGURE_ENV+=		SPHINX_BUILD=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX}
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx-rtd-theme-[0-9]*:../../textproc/py-sphinx-rtd-theme
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinxcontrib-actdiag-[0-9]*:../../textproc/py-sphinxcontrib-actdiag
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinxcontrib-blockdiag-[0-9]*:../../textproc/py-sphinxcontrib-blockdiag
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinxcontrib-nwdiag-[0-9]*:../../textproc/py-sphinxcontrib-nwdiag
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinxcontrib-phpdomain-[0-9]*:../../textproc/py-sphinxcontrib-phpdomain
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinxcontrib-programoutput2-[0-9]*:../../textproc/py-sphinxcontrib-programoutput2
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinxcontrib-seqdiag-[0-9]*:../../textproc/py-sphinxcontrib-seqdiag
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinxcontrib-spelling-[0-9]*:../../textproc/py-sphinxcontrib-spelling
TOOL_DEPENDS+=		p5-Pod-POM-View-Restructured-[0-9]*:../../textproc/p5-Pod-POM-View-Restructured
.endif

#XXX doesn't build
#XXX .if !empty(PKG_OPTIONS:Mwebdav)
#XXX CONFIGURE_ARGS+=	--enable-http
#XXX DEPENDS+=		rsync-[0-9]*:../../net/rsync
#XXX .include "../../textproc/xapian/buildlink3.mk"
#XXX CONFIGURE_ARGS+=	--enable-xapian
#XXX CONFIGURE_ARGS+=	--enable-jmap
#XXX .include "../../archivers/brotli/buildlink3.mk"
#XXX .include "../../time/libical/buildlink3.mk"
#XXX .include "../../textproc/libxml2/buildlink3.mk"
#XXX .include "../../www/nghttp2/buildlink3.mk"
#XXX .include "../../www/wslay/buildlink3.mk"
#XXX DEPENDS+=		vim-share-[0-9]*:../../editors/vim-share
#XXX .include "../../devel/zlib/buildlink3.mk"
#XXX .endif
