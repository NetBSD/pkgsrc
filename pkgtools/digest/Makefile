# $NetBSD: Makefile,v 1.10 2001/03/12 09:08:40 agc Exp $
#
# When adding new digest algorithms, please use rmd160 as the template,
# and bump the VERSION definition.

DISTNAME=	digest-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=   # empty
DISTFILES=      # empty

MAINTAINER=	agc@netbsd.org
HOMEPAGE=       http://www.netbsd.org/Documentation/software/packages.html
COMMENT=	message digest wrapper utility

VERSION=	20010307

EXTRACT_ONLY=   # empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=    # defined
MANCOMPRESSED_IF_MANZ=	YES
PLIST_SRC=	${WRKDIR}/PLIST
BUILD_DEFS+=	MANINSTALL

MAKE_ENV+=	BINDIR=${LOCALBASE}/bin MANDIR=${LOCALBASE}/man
MAKE_ENV+=	VERSION="${VERSION}"

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
MAKE_ENV+=	NETBSD_COMPATIBLE=YES
.endif

post-extract:
	@for FILE in Makefile digest.c digest.1				\
		md5c.c md5.h md5hl.c					\
		rmd160.c rmd160.h rmd160hl.c				\
		sha1.c sha1.h sha1hl.c					\
		sha2.c sha2.h sha2hl.c					\
	; do								\
		${CP} ${FILESDIR}/$$FILE ${WRKSRC};			\
	done

pre-install:
	@${RM} -f ${PLIST_SRC}
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@if [ -n "${MANINSTALL:Mcatinstall}" ]; then			\
		${ECHO} man/cat1/digest.0 >> ${PLIST_SRC};		\
	fi
	@if [ -n "${MANINSTALL:Mmaninstall}" ]; then			\
		${ECHO} man/man1/digest.1 >> ${PLIST_SRC};		\
	fi

.include "../../mk/bsd.pkg.mk"
