# $NetBSD: Makefile,v 1.13 2004/04/01 18:42:25 joda Exp $

DISTNAME=		heimdal-0.6.1
PKGREVISION=		0
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/heimdal/src/		\
			ftp://ftp.sunet.se/pub/unix/admin/mirror-pdc/pub/heimdal/src/

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.pdc.kth.se/heimdal/
COMMENT=		Kerberos 5 implementation

CONFLICTS+=		mit-krb5-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

HEIMDAL_STATEDIR?=	/var/heimdal

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${HEIMDAL_STATEDIR}
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/krb5
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-krb4

# Heimdal's configure script expects to find the readline.h header as
# <readline.h>.
#
BUILDLINK_INCDIRS.readline=	include/readline
.include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
LIBS.SunOS=		-ltermcap

BUILD_DEFS+=		USE_DB4
.if defined(USE_DB4) && !empty(USE_DB4:M[yY][eE][sS])
.include "../../databases/db4/buildlink3.mk"
.else
.include "../../mk/bdb.buildlink3.mk"
.endif

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.include "../../security/openssl/buildlink3.mk"

# XXX Using Heimdal with an LDAP backend isn't supported yet.
#BUILD_DEFS+=		HEIMDAL_USE_LDAP
#.if defined(HEIMDAL_USE_LDAP) && !empty(HEIMDAL_USE_LDAP:M[yY][eE][sS])
#.  include "../../databases/openldap/buildlink3.mk"
#CONFIGURE_ARGS+=	--with-openldap=${BUILDLINK_PREFIX.openldap}
#.endif

# Rename some of Heimdal's applications so they won't conflict with
# other packages.
#
BUILD_DEFS+=	KERBEROS_PREFIX_CMDS
.if !empty(KERBEROS_PREFIX_CMDS:M[yY][eE][sS])
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
	cd ${WRKSRC}; for file in lib/hdb/hdb.h; do			\
		${SED}	-e "s|/var/heimdal|${HEIMDAL_STATEDIR}|g"	\
			$$file > $$file.new;				\
		${MV} -f $$file.new $$file;				\
	done

.include "../../mk/bsd.pkg.mk"
