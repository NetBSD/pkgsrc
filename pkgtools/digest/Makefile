# $NetBSD: Makefile,v 1.35 2003/03/28 21:14:26 wiz Exp $
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

USE_BUILDLINK2=		# defined

GNU_CONFIGURE=		# defined

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		# defined

.include "../../mk/bsd.prefs.mk"

VERSION!=	${AWK} -F "'" '/^PACKAGE_VERSION=/ {print $$2}' \
		${FILESDIR}/configure

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

pre-install:
	-@${MKDIR} ${PKG_DBDIR}

test:
	@${ECHO} "No news is good news"
	@cd ${WRKSRC} && ${SETENV} DIGESTDIR=${WRKSRC} ${SH} ./regress.sh
	@${ECHO} "All tests completed"

.include "../../mk/bsd.pkg.mk"
