# $NetBSD: Makefile,v 1.1.1.1 1998/12/31 14:25:30 frueauf Exp $
#

DISTNAME=	pgp50i-unix-src
PKGNAME=	pgp-5.0i
WRKSRC=		${WRKDIR}/pgp50i/src
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.pgpi.com/pub/pgp/5.0/unix/ \
		ftp://ftp.at.pgpi.com/pub/pgpi/5.0/unix/ \
		ftp://ftp.se.pgpi.com/pub/pgp/5.0/unix/ \
		ftp://ftp.ch.pgpi.com/pub/pgp/5.0/unix/ \
		ftp://ftp.au.pgpi.com/pub/pgp/5.0/unix/

MAINTAINER=	mjl@emsi.priv.at
HOMEPAGE=       http://www.pgpi.com/

BUILD_DEPENDS=	perl:../../lang/perl5

RESTRICTED=	"Cryptographic software"
MIRROR_DISTFILE=no

GNU_CONFIGURE=	YES

PGPLIB=	${PREFIX}/share/pgp5

.include "../../mk/bsd.prefs.mk"

.if !defined(USE_RSAREF2) || ${USE_RSAREF2} != YES && ${USE_RSAREF2} != NO
pre-fetch:
	@${ECHO}
	@${ECHO} The variable USE_RSAREF2 must be set to either YES or NO
	@${ECHO} in order to build this package.  USA residents that are
	@${ECHO} not licensees of the RSA algorithm MUST set this variable
	@${ECHO} to YES.  Users outside the USA MUST set this variable to
	@${ECHO} NO.  Licensees may choose -- NO is faster.
	@${ECHO}
	@${ECHO} On the other hand, this package needs more work to
	@${ECHO} actually work with RSAREF. Sorry.
	@${FALSE}
.endif

post-patch:
	${MV} ${WRKSRC}/man/pgp.1 ${WRKSRC}/man/pgp5.1

post-install:
	-${MKDIR} ${PGPLIB}
	${INSTALL_DATA} ${WRKSRC}/language50.txt ${PGPLIB}

.include "../../mk/bsd.pkg.mk"
