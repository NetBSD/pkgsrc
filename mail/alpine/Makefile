# $NetBSD: Makefile,v 1.2 2007/05/17 21:58:58 abs Exp $
#

DISTNAME=	alpine-0.99
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/alpine/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.washington.edu/alpine/
COMMENT=	Program for Internet News and E-mail

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-ssl-dir=${SSLBASE:Q}
USE_LIBTOOL=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alpine/alpine ${PREFIX}/bin/alpine
	${INSTALL_DATA} ${WRKSRC}/doc/alpine.1 ${PREFIX}/${PKGMANDIR}/man1/alpine.1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
