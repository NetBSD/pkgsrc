# $NetBSD: Makefile,v 1.6 2001/03/10 15:26:15 tron Exp $
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
MANCOMPRESSED_IF_MANZ=	YES
PLIST_SRC=	${WRKDIR}/PLIST
BUILD_DEFS+=	MANINSTALL

DIGEST=			${WRKSRC}/bootstrap-digest
DIGEST_ALGORITHM=	MD5
MAKE_ENV+=		BINDIR=${LOCALBASE}/bin MANDIR=${LOCALBASE}/man
MAKE_ENV+=		CPPFLAGS="${CPPFLAGS} -DVERSION=${VERSION}"

.include "../../mk/bsd.prefs.mk"


post-extract:
	@for FILE in Makefile digest.c digest.1				\
		md5c.c md5.h md5hl.c					\
		rmd160.c rmd160.h rmd160hl.c				\
		sha1.c sha1.h sha1hl.c					\
	; do								\
		${CP} ${FILESDIR}/$$FILE ${WRKSRC};			\
	done
	@${SED} -e 's#$${PREFIX}#${PREFIX}#g' ${SCRIPTDIR}/bootstrap-digest \
	  >${DIGEST}
	@${CHMOD} +x ${DIGEST}

pre-install:
	@${RM} -f ${PLIST_SRC}
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
.if (${OPSYS} != SunOS)
	@for OPT in ${MANINSTALL} broken-solaris-needs-this; do \
	  case $$OPT in \
	    catinstall) \
		${ECHO} man/cat1/digest.0${MANZ:D.gz} >> ${PLIST_SRC}; \
		;; \
	    maninstall) \
		${ECHO} man/man1/digest.1${MANZ:D.gz} >> ${PLIST_SRC}; \
		;; \
	  esac; \
	done
.endif

.include "../../mk/bsd.pkg.mk"
