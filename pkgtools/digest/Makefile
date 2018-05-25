# $NetBSD: Makefile,v 1.62 2018/05/25 13:08:49 joerg Exp $
#
# When adding new digest algorithms, please use rmd160 as the template,
# and bump the VERSION definition.

PKGNAME?=	digest-${VERSION}
CATEGORIES=	pkgtools

MAINTAINER?=	agc@NetBSD.org
HOMEPAGE?=	http://www.NetBSD.org/docs/software/packages.html
COMMENT?=	Message digest wrapper utility
LICENSE=	original-bsd

CHECK_PERMS=		no

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

VERSION!=	${AWK} -F "'" '/^PACKAGE_VERSION=/ {print $$2}' \
		${FILESDIR}/configure

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-test:
	@${ECHO} "No news is good news"
	@cd ${WRKSRC} && ${SETENV} DIGESTDIR=${WRKSRC} ${SH} ./regress.sh
	@${ECHO} "All tests completed"

.include "../../mk/bsd.pkg.mk"
