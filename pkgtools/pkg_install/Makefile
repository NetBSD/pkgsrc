# $NetBSD: Makefile,v 1.13 1999/03/16 15:42:59 tv Exp $
#

# Note to package maintainers:
# To update the distfile of this pkg, cd to /usr/src/usr.sbin,
# "tar pzvcf pkg_install-YYYYMMDD.tar.gz pkg_install" and upload
# that file to ${MASTER_SITE_LOCAL}.
# Also, check PKGTOOLS_REQD value in pkgsrc/mk/bsd.pkg.mk
# (Use "make print-pkgtools_ver" to find the correct value for
#  YYYYMMDD)

DISTNAME=		pkg_install-19990119
CATEGORIES=		pkgtools
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

LOCALBASE=		/usr
PREFIX=			${LOCALBASE}
WRKSRC=			${WRKDIR}/pkg_install
MAKE_ENV+=		BINDIR=/usr/sbin MANDIR=/usr/share/man NOLINT=1
NO_MTREE=		yes
NO_PKG_REGISTER=	yes
NO_PACKAGE=		No package registration is done

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=		yes
.endif

post-install:
	[ -f $${PKG_DBDIR:-/var/db/pkg}/pkgdb.byfile.db ] || \
		pkg_admin rebuild

.include "../../mk/bsd.pkg.mk"
