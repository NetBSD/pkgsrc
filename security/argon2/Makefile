# $NetBSD: Makefile,v 1.1 2015/11/05 08:50:33 wiz Exp $

DISTNAME=	phc-winner-argon2-20151102
PKGNAME=	${DISTNAME:S/phc-winner-//}
CATEGORIES=	security
MASTER_SITES=	https://password-hashing.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/p-h-c/phc-winner-argon2
COMMENT=	Password hash Argon2
LICENSE=	cc0-1.0-universal

WRKSRC=	${WRKDIR}/${DISTNAME:C/-2[0-9]*//}
USE_TOOLS+=	gmake
TEST_TARGET=	test
INSTALLATION_DIRS=	bin lib share/doc/argon2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/argon2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libargon2.* ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/argon2-specs.pdf ${DESTDIR}${PREFIX}/share/doc/argon2
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/argon2

.include "../../mk/bsd.pkg.mk"
