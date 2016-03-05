# $NetBSD: Makefile,v 1.17 2016/03/05 11:29:26 jperkin Exp $

GITHUB_PROJECT= sign
GITHUB_TAG=     1.0.7
DISTNAME=       ${GITHUB_TAG}
PKGNAME=        sign-${DISTNAME}
PKGREVISION=        1
CATEGORIES=	security
MASTER_SITES=   ${MASTER_SITE_GITHUB:=apankrat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://swapped.cc/sign/
COMMENT=	File signing and signature verification utility
LICENSE=	openssl AND 2-clause-bsd

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sign ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/sign.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${LN} -sf sign ${DESTDIR}${PREFIX}/bin/unsign

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
