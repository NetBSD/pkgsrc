# $NetBSD: Makefile,v 1.10 2019/08/11 13:20:58 wiz Exp $

DISTNAME=	shoebill-0.0.5
PKGREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=pruten/}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://github.com/pruten/shoebill/
COMMENT=	Macintosh II emulator that runs A/UX
LICENSE=	2-clause-bsd

# Missing long double math functions
NOT_FOR_PLATFORM=	NetBSD-[0-6]*-*

USE_TOOLS+=	perl gtar
EXTRACT_USING=	gtar

REPLACE_PERL+=	core/macro.pl

DOCDIR=		share/doc/shoebill
INSTALLATION_DIRS= bin ${DOCDIR}

CFLAGS+=	-g3
INSTALL_UNSTRIPPED= yes

do-build:
	( cd ${WRKSRC}/sdl-gui && \
		${PKGSRC_SETENV} CC=${CC:Q} CFLAGS=${CFLAGS:Q} LDFLAGS=${LDFLAGS:Q} \
		${SH} ./lin_build.sh )

do-install:
	${INSTALL_DATA} files/shoebill.usage ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/sdl-gui/shoebill ${DESTDIR}${PREFIX}/bin

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
