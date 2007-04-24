# $NetBSD: Makefile,v 1.1.1.1 2007/04/24 19:35:46 tnn Exp $

DISTNAME=		posix_headers-0.4
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.pkgsrc.org/
COMMENT=		POSIX compatibility headers

NO_PKGTOOLS_REQD_CHECK=	yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_LANGUAGES=
ONLY_FOR_PLATFORM=	HPUX-11.11-* # add more as needed

PLIST_SRC=		${WRKDIR}/PLIST_SRC

POSIX_HEADERS.HPUX=	sys/select.h stdint.h math.h

BUILDING_POSIX_HEADERS=	yes

do-install:
	for h in ${POSIX_HEADERS.${OPSYS}}; do \
		${INSTALL_DATA} ${FILESDIR}/"$$h" ${PREFIX}/include/"$$h"; \
		${ECHO} include/"$$h" >> ${PLIST_SRC}; \
	done

.include "../../mk/bsd.pkg.mk"
