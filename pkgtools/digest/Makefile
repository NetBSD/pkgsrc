# $NetBSD: Makefile,v 1.1.1.1 2001/03/06 11:21:04 agc Exp $
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

VERSION=	20010302

EXTRACT_ONLY=   # empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=    # defined

MAKE_ENV+=	BINDIR=${LOCALBASE}/bin MANDIR=${LOCALBASE}/man
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS} -DVERSION=${VERSION}"

MANCOMPRESSED_IF_MANZ=	yes

do-configure:
	@for f in Makefile digest.c digest.1				\
		md5c.c md5.h md5hl.c					\
		rmd160.c rmd160.h rmd160hl.c				\
		sha1.c sha1.h sha1hl.c					\
	; do								\
		${CP} ${FILESDIR}/$$f ${WRKSRC};			\
	done

.include "../../mk/bsd.pkg.mk"
