# $NetBSD: Makefile,v 1.15 2001/04/30 04:16:11 jlam Exp $
#

DISTNAME=	pgp50i-unix-src
PKGNAME=	pgp5-5.0i
WRKSRC=		${WRKDIR}/pgp50i/src
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.pgpi.com/pub/pgp/5.0/unix/ \
		ftp://ftp.at.pgpi.com/pub/pgpi/5.0/unix/ \
		ftp://ftp.se.pgpi.com/pub/pgp/5.0/unix/ \
		ftp://ftp.ch.pgpi.com/pub/pgp/5.0/unix/ \
		ftp://ftp.au.pgpi.com/pub/pgp/5.0/unix/ \
		ftp://ftp.ifi.uio.no/pub/pgp/5.0/unix/ \
		ftp://ftp.tuwien.ac.at/privacy/pgp/pgpi/5.0/unix/ \
		http://gd.tuwien.ac.at/privacy/pgp/pgpi/5.0/unix/

MAINTAINER=	mjl@netbsd.org
HOMEPAGE=       http://www.pgpi.com/
COMMENT=	New, international, Public-Key encryption and digital signature utility

BUILD_DEPENDS=	perl>=${PERL5_REQD}:../../lang/perl5

CONFLICTS=	pgraf-*  	# Both have a `pgps' executable

CRYPTO=		YES
GNU_CONFIGURE=	YES
USE_RSAREF2=	NO

# use of IDEA as crypto function
LICENCE=	fee-based-commercial-use

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
	${INSTALL_DATA_DIR} ${PGPLIB}
	${INSTALL_DATA} ${WRKSRC}/language50.txt ${PGPLIB}

.include "../../mk/bsd.pkg.mk"
