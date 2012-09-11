# $NetBSD: Makefile,v 1.59 2012/09/11 23:19:34 asau Exp $
#
# When adding new digest algorithms, please use rmd160 as the template,
# and bump the VERSION definition.

DISTNAME?=	digest-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER?=	agc@NetBSD.org
HOMEPAGE?=	http://www.NetBSD.org/docs/software/packages.html
COMMENT?=	Message digest wrapper utility
LICENSE=	original-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CHECK_PERMS=		no

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

VERSION!=	${AWK} -F "'" '/^PACKAGE_VERSION=/ {print $$2}' \
		${FILESDIR}/configure

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

pre-install:
	-@${MKDIR} ${DESTDIR}${PKG_DBDIR}

do-test:
	@${ECHO} "No news is good news"
	@cd ${WRKSRC} && ${SETENV} DIGESTDIR=${WRKSRC} ${SH} ./regress.sh
	@${ECHO} "All tests completed"

.include "../../mk/bsd.pkg.mk"
