# $NetBSD: Makefile,v 1.24 2002/06/21 15:26:07 abs Exp $
#
# When adding new digest algorithms, please use rmd160 as the template,
# and bump the VERSION definition.

DISTNAME=	digest-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=   # empty
DISTFILES=      # empty

MAINTAINER=	agc@netbsd.org
HOMEPAGE=       http://www.netbsd.org/Documentation/software/packages.html
COMMENT=	Message digest wrapper utility

VERSION=	20010807

EXTRACT_ONLY=   # empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=    # defined
MANCOMPRESSED_IF_MANZ=	YES
BUILD_DEFS+=	MANINSTALL

MAKE_ENV+=	BINDIR=${LOCALBASE}/bin MANDIR=${LOCALBASE}/man
MAKE_ENV+=	VERSION="${VERSION}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKEFLAGS+=	NETBSD_COMPATIBLE=YES
MANINSTALL=
.elif ${OPSYS} == "Linux"
CPPFLAGS+=-D__COPYRIGHT\(x\)=\; -D__RCSID\(x\)=\;
.endif
.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
PLIST=	${WRKSRC}/.PLIST
post-install:
	${GREP} -v '^man/cat' ${PKGDIR}/PLIST > ${PLIST}
.endif

post-extract:
	@for FILE in Makefile regress.sh digest.c digest.1		\
		md5c.c md5.h md5hl.c					\
		rmd160.c rmd160.h rmd160hl.c				\
		sha1.c sha1.h sha1hl.c					\
		sha2.c sha2.h sha2hl.c					\
	; do								\
		${CP} ${FILESDIR}/$$FILE ${WRKSRC};			\
	done

test:
	@${ECHO} "No news is good news"
	@cd ${WRKSRC} && ${SETENV} DIGESTDIR=${WRKSRC} ${SH} ./regress.sh
	@${ECHO} "All tests completed"

.include "../../mk/bsd.pkg.mk"
