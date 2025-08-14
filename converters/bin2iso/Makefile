# $NetBSD: Makefile,v 1.1 2025/08/14 09:32:31 nia Exp $

DISTNAME=	bin2iso-2.0
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITLAB:=bunnylin/}
GITLAB_PROJECT=	bin2iso

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/bunnylin/bin2iso
COMMENT=	Convert CUE/BIN files to WAV/ISO
#LICENSE=	none

USE_TOOLS+=	gmake
MAKE_FLAGS=	CFLAGS=${CFLAGS:Q} LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/bin2iso

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin2iso ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md \
	    ${DESTDIR}${PREFIX}/share/doc/bin2iso
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG \
	    ${DESTDIR}${PREFIX}/share/doc/bin2iso

.include "../../mk/bsd.pkg.mk"
