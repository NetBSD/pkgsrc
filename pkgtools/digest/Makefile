# $NetBSD: Makefile,v 1.43 2004/10/14 03:13:00 atatat Exp $
#
# When adding new digest algorithms, please use rmd160 as the template,
# and bump the VERSION definition.

DISTNAME?=	digest-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER?=	agc@NetBSD.org
HOMEPAGE?=	http://www.NetBSD.org/Documentation/software/packages.html
COMMENT?=	Message digest wrapper utility

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		# defined

# XXX Remove the following two lines after pkgsrc/bootstrap is up and
# XXX running.
USE_NATIVE_GCC=		yes
USE_DIGEST=		no

.include "../../mk/bsd.prefs.mk"

VERSION!=	${AWK} -F "'" '/^PACKAGE_VERSION=/ {print $$2}' \
		${FILESDIR}/configure

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

pre-install:
	-@${MKDIR} ${PKG_DBDIR}

do-test:
	@${ECHO} "No news is good news"
	@cd ${WRKSRC} && ${SETENV} DIGESTDIR=${WRKSRC} ${SH} ./regress.sh
	@${ECHO} "All tests completed"

.include "../../mk/bsd.pkg.mk"
