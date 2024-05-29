# $NetBSD: Makefile,v 1.13 2024/05/29 16:31:19 adam Exp $

DISTNAME=	cmusfm-0.3.3
PKGREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=Arkq/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Arkq/cmusfm
COMMENT=	Last.fm standalone scrobbler for the cmus music player
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	autoconf automake pkg-config
GNU_CONFIGURE=	yes

TOOL_DEPENDS+=	autoconf-archive-[0-9]*:../../devel/autoconf-archive

INSTALLATION_DIRS=	bin ${DOCDIR}

DOCDIR=			${PREFIX}/share/doc/cmusfm

TEST_TARGET=		check

LDFLAGS.SunOS+=		-lsocket -lnsl

pre-configure:
	cd ${WRKSRC} && autoreconf -i

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cmusfm ${DESTDIR}${PREFIX}/bin/cmusfm
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
