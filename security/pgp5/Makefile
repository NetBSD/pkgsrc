# $NetBSD: Makefile,v 1.32 2007/12/02 11:35:41 wiz Exp $
#

DISTNAME=	pgp50i-unix-src
PKGNAME=	pgp5-5.0i
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.pgpi.com/pub/pgp/5.0/unix/ \
		ftp://ftp.au.pgpi.com/pub/pgp/5.0/unix/ \
		ftp://ftp.ifi.uio.no/pub/pgp/5.0/unix/ \
		ftp://ftp.tuwien.ac.at/privacy/pgp/5.0/unix/ \
		http://ftp.tuwien.ac.at/privacy/pgp/5.0/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pgpi.org/
COMMENT=	Public-key encryption and digital signature utilities (v5)

USE_TOOLS+=	perl

CONFLICTS=	pgraf-[0-9]*  	# Both have a `pgps' executable

WRKSRC=		${WRKDIR}/pgp50i/src
CRYPTO=		YES
GNU_CONFIGURE=	YES

# use of IDEA as crypto function
LICENSE=	fee-based-commercial-use

PGPLIB=	${PREFIX}/share/pgp5

post-patch:
	${MV} ${WRKSRC}/man/pgp.1 ${WRKSRC}/man/pgp5.1

post-install:
	${INSTALL_DATA_DIR} ${PGPLIB}
	${INSTALL_DATA} ${WRKSRC}/language50.txt ${PGPLIB}

.include "../../mk/bsd.pkg.mk"
