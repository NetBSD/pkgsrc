# $NetBSD: Makefile,v 1.18 2022/08/11 05:08:20 gutteridge Exp $

DISTNAME=	nono-0.4.2
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.pastel-flower.jp/~isaki/nono/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pastel-flower.jp/~isaki/nono/
COMMENT=	OMRON LUNA-I/LUNA-88K (and SHARP X68030) emulator
LICENSE=	nono-license AND fsharp-license	# nono uses X68030 IPLROM image

# Honor pkgsrc settings. Don't use -Werror.
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	CXXFLAGS=${CXXFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS="${LDFLAGS} -pthread"

MAKE_FLAGS+=	BINOWN=${BINOWN}
MAKE_FLAGS+=	BINGRP=${BINGRP}

RESTRICTED=	License disallows binary redistribution

NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

GCC_REQD+=		7

USE_TOOLS+=		awk:build xgettext
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++14

INSTALLATION_DIRS+=	share/doc/nono

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DESTDIR}${PREFIX}/share/doc/nono
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/nono

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
