# $NetBSD: Makefile,v 1.26 2005/10/08 22:36:49 rillig Exp $
#

DISTNAME=	pgp50i-unix-src
PKGNAME=	pgp5-5.0i
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.pgpi.com/pub/pgp/5.0/unix/ \
		ftp://ftp.at.pgpi.com/pub/pgpi/5.0/unix/ \
		ftp://ftp.se.pgpi.com/pub/pgp/5.0/unix/ \
		ftp://ftp.ch.pgpi.com/pub/pgp/5.0/unix/ \
		ftp://ftp.au.pgpi.com/pub/pgp/5.0/unix/ \
		ftp://ftp.ifi.uio.no/pub/pgp/5.0/unix/ \
		ftp://ftp.tuwien.ac.at/privacy/pgp/5.0/unix/ \
		http://ftp.tuwien.ac.at/privacy/pgp/5.0/unix/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=       http://www.pgpi.com/
COMMENT=	Public-key encryption and digital signature utilities (v5)

USE_TOOLS+=	perl

CONFLICTS=	pgraf-[0-9]*  	# Both have a `pgps' executable

WRKSRC=		${WRKDIR}/pgp50i/src
CRYPTO=		YES
GNU_CONFIGURE=	YES

# use of IDEA as crypto function
LICENCE=	fee-based-commercial-use

PGPLIB=	${PREFIX}/share/pgp5

post-patch:
	${MV} ${WRKSRC}/man/pgp.1 ${WRKSRC}/man/pgp5.1

post-install:
	${INSTALL_DATA_DIR} ${PGPLIB}
	${INSTALL_DATA} ${WRKSRC}/language50.txt ${PGPLIB}

.include "../../mk/bsd.pkg.mk"
