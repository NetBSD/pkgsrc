# $NetBSD: options.mk,v 1.6 2021/10/22 07:31:54 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.heimdal
PKG_SUPPORTED_OPTIONS=	inet6 kerberos-prefix-cmds ldap
PKG_SUGGESTED_OPTIONS=	inet6 kerberos-prefix-cmds

.include "../../mk/bsd.options.mk"

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

###
### Support using LDAP as a KDC backend.
###
PLIST_VARS+=		ldap
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openldap=${BUILDLINK_PREFIX.openldap-client}
PLIST.ldap=		yes
INSTALLATION_DIRS+=	share/examples/heimdal

.PHONY: heimdal-ldap-schema
post-install: heimdal-ldap-schema
heimdal-ldap-schema:
	${INSTALL_DATA} ${WRKSRC}/lib/hdb/hdb.schema			\
		${DESTDIR}${PREFIX}/share/examples/heimdal
.endif

###
### Rename some of Heimdal's applications so they won't conflict with
### other packages.
###
.if !empty(PKG_OPTIONS:Mkerberos-prefix-cmds)
KRB5_PREFIX=		k
HEIMDAL_TRANSFORM=	s/^su/${KRB5_PREFIX}&/;
CONFIGURE_ARGS+=	--program-transform-name=${HEIMDAL_TRANSFORM:Q}
.else
KRB5_PREFIX=		# empty
.endif

PLIST_SUBST+=		KRB5_PREFIX=${KRB5_PREFIX:Q}
