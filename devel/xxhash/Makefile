# $NetBSD: Makefile,v 1.1 2018/09/10 13:47:31 fhajny Exp $

DISTNAME=	xxhash-0.6.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cyan4973/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Cyan4973/xxHash/
COMMENT=	Extremely fast non-cryptographic hash algorithm
LICENSE=	2-clause-bsd

GITHUB_PROJECT=	xxHash
GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin include ${PKGMANDIR}/man1

do-install:
	${INSTALL_DATA} ${WRKSRC}/xxhash.h ${DESTDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/xxhsum.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/xxhsum ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
