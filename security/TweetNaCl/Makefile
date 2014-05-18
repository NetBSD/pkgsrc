# $NetBSD: Makefile,v 1.2 2014/05/18 13:32:32 wiz Exp $

DISTNAME=	TweetNaCl-${VERSION}
VERSION=	20140427
CATEGORIES=	security
MASTER_SITES=	http://tweetnacl.cr.yp.to/${VERSION}/
DISTFILES=	tweetnacl.c tweetnacl.h

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tweetnacl.cr.yp.to/
COMMENT=	World's first auditable high-security cryptographic library
LICENSE=	public-domain

DIST_SUBDIR=	${DISTNAME}
USE_LIBTOOL=	yes

WRKSRC=		${WRKDIR}
INSTALLATION_DIRS=	include lib

do-build:
	cd ${WRKSRC} && libtool --mode=compile --tag=C ${CC} ${CFLAGS} ${CPPFLAGS} -c -o tweetnacl.lo tweetnacl.c
	cd ${WRKSRC} && libtool --mode=link --tag=C ${CC} ${LDFLAGS} -rpath ${PREFIX}/lib -o libtweetnacl.la tweetnacl.lo

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} tweetnacl.h ${DESTDIR}${PREFIX}/include
	cd ${WRKSRC} && libtool --mode=install ${INSTALL_LIB} libtweetnacl.la ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
