# $NetBSD: Makefile,v 1.4 2017/12/30 11:34:12 adam Exp $

DISTNAME=	${GITHUB_PROJECT}
PKGNAME=	${DISTNAME:S/phc-winner-//}-${GITHUB_TAG}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=P-H-C/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://password-hashing.net/
COMMENT=	Password hash Argon2
LICENSE=	cc0-1.0-universal OR apache-2.0

GITHUB_PROJECT=	phc-winner-argon2
GITHUB_TAG=	20171227

USE_TOOLS+=	gmake
TEST_TARGET=	test

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/doc/argon2

OPSYSVARS+=		SO_SUFFIX
SO_SUFFIX.Darwin=	dylib
SO_SUFFIX.*=		so
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/argon2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/include/argon2.h ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libargon2.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libargon2.${SO_SUFFIX} ${DESTDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/man/argon2.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/argon2-specs.pdf ${DESTDIR}${PREFIX}/share/doc/argon2
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/argon2

.include "../../mk/bsd.pkg.mk"
