# $NetBSD: Makefile,v 1.40 2005/06/20 09:51:02 lha Exp $

DISTNAME=	heimdal-0.6.5
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.pdc.kth.se/pub/heimdal/src/	\
		ftp://ftp.sunet.se/pub/unix/admin/mirror-pdc/heimdal/src/

MAINTAINER=	lha@NetBSD.org
HOMEPAGE=	http://www.pdc.kth.se/heimdal/
COMMENT=	Kerberos 5 implementation

CONFLICTS+=	mit-krb5-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		bison

HEIMDAL_STATEDIR?=	${VARBASE}/heimdal

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${HEIMDAL_STATEDIR}
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/krb5
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-krb4

CFLAGS.Darwin+= -DBIND_8_COMPAT

.include "../../mk/bsd.prefs.mk"

# Heimdal's configure script expects to find the readline.h header as
# <readline.h>.
#
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
BUILDLINK_INCDIRS.readline=	include/readline
BROKEN_READLINE_DETECTION=	yes
.include "../../devel/readline/buildlink3.mk"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
USE_OLD_DES_API=	yes
.include "../../security/openssl/buildlink3.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.heimdal
PKG_SUPPORTED_OPTIONS=	db4 ldap kerberos-prefix-cmds
PKG_OPTIONS_LEGACY_VARS+=	KERBEROS_PREFIX_CMDS:kerberos-prefix-cmds
PKG_OPTIONS_LEGACY_OPTS+=	prefix-cmds:kerberos-prefix-cmds

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdb4)
.  include "../../databases/db4/buildlink3.mk"
.else
.  include "../../mk/bdb.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openldap=${BUILDLINK_PREFIX.openldap}
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
PLIST_SUBST+=		KRB5_PREFIX=${KRB5_PREFIX}
CONFIGURE_ARGS+=	--program-transform-name="${HEIMDAL_TRANSFORM}"

USE_PKGINSTALL=		yes
OWN_DIRS_PERMS=		${HEIMDAL_STATEDIR} ${ROOT_USER} ${ROOT_GROUP} 0700
RCD_SCRIPTS=		kdc
INFO_FILES=		heimdal.info

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

pre-configure:
	cd ${WRKSRC}; for f in lib/hdb/hdb.h; do			\
		${SED}	-e "s|/var/heimdal|${HEIMDAL_STATEDIR}|g"	\
			$$f > $$f.new;					\
		${MV} -f $$f.new $$f;					\
	done

.include "../../mk/bsd.pkg.mk"
