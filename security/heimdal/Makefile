# $NetBSD: Makefile,v 1.1.1.1 2004/01/10 14:56:45 jlam Exp $

DISTNAME=		heimdal-0.6
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/heimdal/src/		\
			ftp://ftp.pdc.kth.se/pub/heimdal/src/old/	\
			ftp://ftp.pdc.kth.se/pub/heimdal/src/snapshots/

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.pdc.kth.se/heimdal/
COMMENT=		Kerberos 5 implementation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

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

USE_DB185=		yes
.include "../../databases/db/buildlink3.mk"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.include "../../security/openssl/buildlink3.mk"

# XXX Using heimdal with an LDAP backend isn't supported yet.
#BUILD_DEFS+=		HEIMDAL_USE_LDAP
#.if defined(HEIMDAL_USE_LDAP) && !empty(HEIMDAL_USE_LDAP:M[yY][eE][sS])
#.  include "../../databases/openldap/buildlink3.mk"
#CONFIGURE_ARGS+=	--with-openldap=${BUILDLINK_PREFIX.openldap}
#.endif

# Rename heimdal's ftp/ftpd to kftp/kftpd so we don't conflict with
# net/tnftp and net/tnftpd.
#
CONFIGURE_ARGS+=	--program-transform-name=${HEIMDAL_TRANSFORM}
HEIMDAL_TRANSFORM=	"s/^ftp/kftp/"

USE_PKGINSTALL=		yes
OWN_DIRS_PERMS=		${HEIMDAL_STATEDIR} ${ROOT_USER} ${ROOT_GROUP} 0700

pre-configure:
	cd ${WRKSRC}; for file in lib/hdb/hdb.h; do			\
		${SED}	-e "s|/var/heimdal|${HEIMDAL_STATEDIR}|g"	\
			$$file > $$file.new;				\
		${MV} -f $$file.new $$file;				\
	done

.include "../../mk/bsd.pkg.mk"
