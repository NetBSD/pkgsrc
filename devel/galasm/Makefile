# $NetBSD: Makefile,v 1.2 2024/06/10 16:48:35 thorpej Exp $

# There is no tag on Github for 2.1, but that's what the program
# claims to be when you run it.
GALASM_VERSION=2.1.0.2023.11.29

DISTNAME=	GALasm-${GALASM_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=daveho/}
GITHUB_TAG=	c376d566e88d480160b002f6e085810648e36cb5

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
