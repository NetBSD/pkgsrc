# $NetBSD: Makefile,v 1.30 2002/12/21 04:06:10 schmonz Exp $
#
# When adding new digest algorithms, please use rmd160 as the template,
# and bump the VERSION definition.

DISTNAME=	digest-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.netbsd.org/Documentation/software/packages.html
COMMENT=	Message digest wrapper utility

USE_BUILDLINK2=		no

GNU_CONFIGURE=		# defined

NO_CHECKSUM=		# defined
NO_PATCH=		# defined
MANCOMPRESSED_IF_MANZ=	# defined
BUILD_DEFS+=		MANINSTALL

.include "../../mk/bsd.prefs.mk"

VERSION!=	${AWK} -F "'" '/^PACKAGE_VERSION=/ {print $$2}' \
		${FILESDIR}/configure

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

test:
	@${ECHO} "No news is good news"
	@cd ${WRKSRC} && ${SETENV} DIGESTDIR=${WRKSRC} ${SH} ./regress.sh
	@${ECHO} "All tests completed"

.include "../../mk/bsd.pkg.mk"
