# $NetBSD: Makefile,v 1.3 2026/10/09 09:26:43 hauke Exp $

DISTNAME=	ntvcm
PKGNAME=	ntvcm-0.0.20261009
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=davidly/}
GITHUB_PROJECT=	ntvcm
GITHUB_TAG=	59c0b63d5cb1a14b6ee342df9440dee29e67a79f	# 2026-10-09

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://github.com/davidly/ntvcm?tab=readme-ov-file\#readme
COMMENT=	Run i8080/Z80 .COM binaries in CP/M 2.2 emulation
LICENSE=	cc0-1.0-universal

USE_LANGUAGES=	c++

WRKSRC=		${WRKDIR}/${DISTNAME}-${GITHUB_TAG}

USE_TOOLS=	gmake
MAKE_FILE=	makefile

DOCDIR=		share/doc/ntvcm

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${DOCDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_MAN} ${FILESDIR}/ntvcm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/ntvcm ${DESTDIR}${PREFIX}/bin/ntvcm

do-test:
	cd ${WRKSRC}/tests && ../ntvcm -8 8080EX1.COM
	cd ${WRKSRC}/tests && ../ntvcm -8 8080EXER.COM
	cd ${WRKSRC}/tests && ../ntvcm -8 8080PRE.COM
	cd ${WRKSRC}/tests && ../ntvcm -8 CPUTEST.COM
	cd ${WRKSRC}/tests && ../ntvcm -8 TEST.COM
	cd ${WRKSRC}/tests && ../ntvcm -8 TST8080.COM
	cd ${WRKSRC}/tests && ../ntvcm TST8080.COM
	cd ${WRKSRC} && ./ntvcm z80test/zexdoc.com
	cd ${WRKSRC} && ./ntvcm z80test/zexall.com

.include "../../mk/bsd.pkg.mk"
