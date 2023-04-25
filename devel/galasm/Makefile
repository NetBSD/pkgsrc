# $NetBSD: Makefile,v 1.1 2023/04/25 03:28:37 thorpej Exp $

# There is no tag on Github for 2.1, but that's what the program
# claims to be when you run it.
GALASM_VERSION=2.1

DISTNAME=	GALasm-${GALASM_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=daveho/}
GITHUB_TAG=	290d0cf9dcd0d9749167c9019ad694db2c3360dd

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/daveho/GALasm
COMMENT=	Portable GAL assembler
LICENSE=	galasm-license

RESTRICTED=	Commercial use is strictly forbidden

NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

INSTALLATION_DIRS=	bin share/doc/galasm

do-build:
	cd ${WRKSRC}/src && ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/galasm \
	    ${DESTDIR}${PREFIX}/bin
	for file in ${WRKSRC}/galer/*; do \
		${INSTALL_DATA} $$file ${DESTDIR}${PREFIX}/share/doc/galasm; \
	done

.include "../../mk/bsd.pkg.mk"
