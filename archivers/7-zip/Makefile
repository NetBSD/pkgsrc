# $NetBSD: Makefile,v 1.5 2024/06/14 20:28:47 adam Exp $

DISTNAME=	7z2406-src
PKGNAME=	7-zip-24.06
CATEGORIES=	archivers
MASTER_SITES=	https://www.7-zip.org/a/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.7-zip.org/
COMMENT=	Latest command-line tool for .7z and some archive formats
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

BUILD_DIRS+=	CPP/7zip/Bundles/Alone2
MAKE_FILE=	makefile.gcc

# Disable -Werror.
MAKE_FLAGS+=	CFLAGS_WARN_WALL=${CFLAGS:Q}

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

# Disable RAR archive file support licensed under unRAR license.
# You can see file listing and extract files without compression.
BUILD_MAKE_FLAGS+=	DISABLE_RAR_COMPRESS=1

INSTALLATION_DIRS+=	bin

SUBST_CLASSES+=		crlf
SUBST_MESSAGE.crlf=	Converting CRLF to LF.
SUBST_STAGE.crlf=	post-extract
SUBST_FILES.crlf=	CPP/7zip/Common/*
SUBST_FILES.crlf+=	CPP/7zip/UI/Common/*
SUBST_FILES.crlf+=	CPP/Windows/*
SUBST_FILES.crlf+=	C/*
SUBST_FILTER_CMD.crlf=	${TR} -d '\r'

# Fix parallel build
pre-build:
	${MKDIR} ${WRKSRC}/CPP/7zip/Bundles/Alone2/_o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/CPP/7zip/Bundles/Alone2/_o/7zz \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
