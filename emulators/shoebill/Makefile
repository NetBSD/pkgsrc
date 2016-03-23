# $NetBSD: Makefile,v 1.3 2016/03/23 15:10:46 hauke Exp $

GITHUB_PROJECT=	shoebill
DISTNAME=	0.0.5
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=pruten/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=pruten/shoebill/}
COMMENT=	Macintosh II emulator that runs A/UX
LICENSE=	2-clause-bsd

# Missing long double math functions
NOT_FOR_PLATFORM=	NetBSD-[0-6]*-*

USE_TOOLS+=	perl gtar
EXTRACT_USING=	gtar

REPLACE_PERL+=	core/macro.pl

WRKSRC=		${WRKDIR}/${PKGNAME}

DOCDIR=		share/doc/shoebill
INSTALLATION_DIRS= bin ${DOCDIR}

CFLAGS+=	-g3
INSTALL_UNSTRIPPED= yes

do-build:
	( cd ${WRKSRC}/sdl-gui && \
		${ENV} CC=${CC:Q} CFLAGS=${CFLAGS:Q} LDFLAGS=${LDFLAGS:Q} \
		${SH} ./lin_build.sh )

do-install:
	${INSTALL_DATA} files/shoebill.usage ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/sdl-gui/shoebill ${DESTDIR}${PREFIX}/bin

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
