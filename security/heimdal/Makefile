# $NetBSD: Makefile,v 1.64 2008/01/18 05:09:37 tnn Exp $

DISTNAME=	heimdal-0.7.2
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.pdc.kth.se/pub/heimdal/src/	\
		ftp://ftp.sunet.se/pub/unix/admin/mirror-pdc/heimdal/src/

MAINTAINER=	lha@NetBSD.org
HOMEPAGE=	http://www.pdc.kth.se/heimdal/
COMMENT=	Kerberos 5 implementation

CONFLICTS+=	arla-[0-9]*
CONFLICTS+=	mit-krb5-[0-9]*
CONFLICTS+=	openafs-[0-9]*
CONFLICTS+=	gss-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex
MAKE_ENV+=		INSTALL_CATPAGES=no

HEIMDAL_STATEDIR?=	${VARBASE}/heimdal

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${HEIMDAL_STATEDIR:Q}
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/krb5
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-krb4
CONFIGURE_ARGS+=	--enable-kcm

CFLAGS.Darwin+=		-DBIND_8_COMPAT

# Though Solaris has a <vis.h> header, it does something very unrelated
# to the BSD <vis.h> header.
OPSYSVARS+=		CONFIGURE_ENV
CONFIGURE_ENV.SunOS+=	ac_cv_header_vis_h=no

# Force building and installing Heimdal's own compile_et.
CONFIGURE_ENV+=		COMPILE_ET=no

.include "../../mk/bsd.prefs.mk"

.if defined(ABI)
CONFIGURE_ARGS+=	--with-mips-abi=${ABI}
.endif

# Heimdal's configure script expects to find the readline.h header as
# <readline.h>.
#
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
CPPFLAGS+=		-I${BUILDLINK_PREFIX.readline}/include/readline
BROKEN_READLINE_DETECTION=	yes
.include "../../devel/readline/buildlink3.mk"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
.include "../../security/openssl/buildlink3.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.heimdal
PKG_SUPPORTED_OPTIONS=	kerberos-prefix-cmds ldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openldap=${BUILDLINK_PREFIX.openldap-client}
PLIST_SUBST+=		LDAP=""

post-install: heimdal-ldap-schema
heimdal-ldap-schema:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/heimdal
	${INSTALL_DATA} ${WRKSRC}/lib/hdb/hdb.schema			\
		${PREFIX}/share/examples/heimdal
.else
PLIST_SUBST+=		LDAP="@comment "
.endif

# Rename some of Heimdal's applications so they won't conflict with
# other packages.
#
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

.if ${OPSYS} == "IRIX"
PLIST_SUBST+=		IF_IRIX=""
.else
PLIST_SUBST+=		IF_IRIX="@comment "
.endif

OWN_DIRS_PERMS=		${HEIMDAL_STATEDIR} ${ROOT_USER} ${ROOT_GROUP} 0700
SPECIAL_PERMS=		${PREFIX}/bin/${KRB5_PREFIX}su ${SETUID_ROOT_PERMS}
RCD_SCRIPTS=		kadmind kcm kdc kpasswdd
INFO_FILES=		# PLIST

# Dynamically determine the "replacement" headers for things missing
# in the base system and add them to the PLIST.
#
GENERATE_PLIST+=	\
	( cd ${WRKSRC}/lib/roken && ${MAKE_PROGRAM} print-xheaders |	\
	  ${XARGS} -n 1 | ${SED} -e "s,^,include/krb5/," );		\
	${ECHO} "@dirrm include/krb5";

# Fix some places in the Heimdal sources that don't point to the correct
# Kerberized binaries when exec'ing programs.
#
SUBST_CLASSES+=		heimdal
SUBST_STAGE.heimdal=	pre-configure
SUBST_FILES.heimdal=	appl/rcp/rcp.c appl/rcp/rcp_locl.h		\
			appl/rsh/rsh_locl.h				\
			appl/telnet/telnetd/telnetd.h
SUBST_SED.heimdal=							\
	-e "/RSH_PROGRAM/s,rsh,${KRB5_PREFIX}rsh,g"			\
	-e "/PATH_RSH/s,\"/usr/bin/rsh\",BINDIR \"${KRB5_PREFIX}rsh\",g" \
	-e "/PATH_RSH/s,/rsh,/${KRB5_PREFIX}rsh,g"			\
	-e "/PATH_LOGIN/s,/login,/${KRB5_PREFIX}login,g"

.include "../../mk/bdb.buildlink3.mk"

pre-configure:
	cd ${WRKSRC}; for f in lib/hdb/hdb.h; do			\
		${SED}	-e "s|/var/heimdal|${HEIMDAL_STATEDIR}|g"	\
			$$f > $$f.new;					\
		${MV} -f $$f.new $$f;					\
	done

.include "../../mk/bsd.pkg.mk"
