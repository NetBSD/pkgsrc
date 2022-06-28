# $NetBSD: Makefile,v 1.54 2022/06/28 11:35:50 wiz Exp $

DISTNAME=	pgp50i-unix-src
PKGNAME=	pgp5-5.0i
PKGREVISION=	11
CATEGORIES=	security
#MASTER_SITES=	ftp://ftp.pgpi.com/pub/pgp/5.0/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pgpi.org/
COMMENT=	Public-key encryption and digital signature utilities (v5)
LICENSE=	pgp5-license

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	perl

CONFLICTS=	pgraf-[0-9]*  	# Both have a `pgps' executable

WRKSRC=		${WRKDIR}/pgp50i/src
GNU_CONFIGURE=	YES

PGPLIB=	${PREFIX}/share/pgp5

INSTALLATION_DIRS=	bin ${PGPLIB}

post-patch:
	${MV} ${WRKSRC}/man/pgp.1 ${WRKSRC}/man/pgp5.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/language50.txt ${DESTDIR}${PGPLIB}

.include "../../mk/bsd.pkg.mk"
