# $NetBSD: Makefile,v 1.3 2007/06/12 13:29:50 joerg Exp $
#

DISTNAME=	alpine-0.99
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/alpine/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.washington.edu/alpine/
COMMENT=	Program for Internet News and E-mail

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-ssl-dir=${SSLBASE:Q}
USE_LIBTOOL=	yes

INSTALLATION_DIRS=	bin ${PKMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alpine/alpine ${DESTDIR}${PREFIX}/bin/alpine
	${INSTALL_MAN} ${WRKSRC}/doc/alpine.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/alpine.1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
