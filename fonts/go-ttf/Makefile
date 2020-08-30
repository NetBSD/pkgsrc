# $NetBSD: Makefile,v 1.4 2020/08/30 20:29:46 tnn Exp $

DISTNAME=	ttfs
PKGNAME=	go-ttf-2.008
CATEGORIES=	fonts
#MASTER_SITES=	https://go.googlesource.com/image/+archive/${COMMIT_ID}/font/gofont/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://blog.golang.org/go-fonts
COMMENT=	Family of high-quality WGL4 TrueType fonts created for the Go project
LICENSE=	modified-bsd

COMMIT_ID=	f03a046406d4d7fbfd4ed29f554da8f6114049fc
DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR}

do-build:

do-install:
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
