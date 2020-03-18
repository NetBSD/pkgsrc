# $NetBSD: options.mk,v 1.4 2020/03/18 13:18:57 gdt Exp $

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
HEIMDAL_TRANSFORM=	s/^ftp/${KRB5_PREFIX}&/;			\
			s/^login/${KRB5_PREFIX}&/;			\
			s/^${KRB5_PREFIX}login.access/login.access/;	\
			s/^rcp/${KRB5_PREFIX}&/;			\
			s/^rsh/${KRB5_PREFIX}&/;			\
			s/^su/${KRB5_PREFIX}&/;				\
			s/^telnet/${KRB5_PREFIX}&/
.else
KRB5_PREFIX=		# empty
HEIMDAL_TRANSFORM=	s/^ftp/k&/
.endif

PLIST_SUBST+=		KRB5_PREFIX=${KRB5_PREFIX:Q}
CONFIGURE_ARGS+=	--program-transform-name=${HEIMDAL_TRANSFORM:Q}
#
# Fix some places in the Heimdal sources that don't point to the correct
# Kerberized binaries when exec'ing programs.
#
SUBST_CLASSES+=		heimdal
SUBST_STAGE.heimdal=	pre-configure
SUBST_FILES.heimdal=	appl/rcp/rcp.c appl/rcp/rcp_locl.h
SUBST_FILES.heimdal+=	appl/rsh/rsh_locl.h
SUBST_FILES.heimdal+=	appl/telnet/telnetd/telnetd.h
SUBST_SED.heimdal=	-e "/RSH_PROGRAM/s,rsh,${KRB5_PREFIX}rsh,g"
SUBST_SED.heimdal+=	-e "/PATH_RSH/s,\"/usr/bin/rsh\",BINDIR \"${KRB5_PREFIX}rsh\",g"
SUBST_SED.heimdal+=	-e "/PATH_RSH/s,/rsh,/${KRB5_PREFIX}rsh,g"
SUBST_SED.heimdal+=	-e "/PATH_LOGIN/s,/login,/${KRB5_PREFIX}login,g"
