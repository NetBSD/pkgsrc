# $NetBSD: Makefile,v 1.24 1999/08/19 07:32:59 tron Exp $

# Note to package maintainers:
# To update the distfile of this pkg, cd to /usr/src/usr.sbin,
# "tar pzvcf pkg_install-YYYYMMDD.tar.gz pkg_install" and upload
# that file to ${MASTER_SITE_LOCAL}.
# Also, check PKGTOOLS_REQD value in pkgsrc/mk/bsd.pkg.mk
# (Use "make show-pkgtools-version" to find the correct value
#  for YYYYMMDD)

DISTNAME=		pkg_install-19990819
CATEGORIES=		pkgtools
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/pkg_install
MAKE_ENV+=		BINDIR=/usr/sbin MANDIR=/usr/share/man NOLINT=1
NO_CONFIGURE=		yes
NO_MTREE=		yes
NO_PATCH=		yes
NO_PKG_REGISTER=	yes
NO_PACKAGE=		No package registration is done
MANCOMPRESSED_IF_MANZ=	yes

.include "../../mk/bsd.prefs.mk"

LOCALBASE=		/usr

post-install:
	if [ ! -f $${PKG_DBDIR:-/var/db/pkg}/pkgdb.byfile.db ]; then \
		if [ ! -d $${PKG_DBDIR:-/var/db/pkg} ]; then \
			${MKDIR} $${PKG_DBDIR:-/var/db/pkg}; \
		fi; \
		pkg_admin rebuild ; \
	fi

.include "../../mk/bsd.pkg.mk"
