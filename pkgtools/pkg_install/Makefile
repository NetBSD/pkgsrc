# $NetBSD: Makefile,v 1.8 1998/11/09 14:45:06 hubertf Exp $
#

# Note to package maintainers:
# To update the distfile of this pkg, cd to /usr/src/usr.sbin,
# "tar vcf pkg_install-YYYYMMDD.tar.gz pkg_install" and upload
# that file to ${MASTER_SITE_LOCAL}.
# Also, check PKGTOOLS_REQD value in pkgsrc/mk/bsd.pkg.mk
# (Use "make print-pkgtools_ver" to find correct value)

DISTNAME=		pkg_install-19981026
CATEGORIES=		pkgtools
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

PREFIX=			/usr
WRKSRC=			${WRKDIR}/pkg_install
ALL_TARGET=		depend all
MAKE_ENV+=		BINDIR=/usr/sbin MANDIR=/usr/share/man
NO_PKG_REGISTER=	yes
NO_PACKAGE=		No package registration is done

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=		yes
.endif

.include "../../mk/bsd.pkg.mk"
