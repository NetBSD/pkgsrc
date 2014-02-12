# $NetBSD: Makefile,v 1.15 2014/02/12 23:18:37 tron Exp $
#

DISTNAME=	sign-1.0.4
PKGREVISION=	6
CATEGORIES=	security
MASTER_SITES=	http://swapped.cc/sign/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://swapped.cc/sign/
COMMENT=	File signing and signature verification utility

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sign ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/sign.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${LN} -sf sign ${DESTDIR}${PREFIX}/bin/unsign

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
