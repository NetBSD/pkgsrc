# $NetBSD: Makefile,v 1.35 2009/06/30 00:07:22 joerg Exp $
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
# use of IDEA as crypto function
LICENSE=	idea-license

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	perl

CONFLICTS=	pgraf-[0-9]*  	# Both have a `pgps' executable

WRKSRC=		${WRKDIR}/pgp50i/src
CRYPTO=		YES
GNU_CONFIGURE=	YES

PGPLIB=	${PREFIX}/share/pgp5

INSTALLATION_DIRS=	bin ${PGPLIB}

post-patch:
	${MV} ${WRKSRC}/man/pgp.1 ${WRKSRC}/man/pgp5.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/language50.txt ${DESTDIR}${PGPLIB}

.include "../../mk/bsd.pkg.mk"
