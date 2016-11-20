# $NetBSD: Makefile,v 1.2 2016/11/20 20:05:32 wiz Exp $

DISTNAME=	ttfs
PKGNAME=	go-ttf-0.0.20161118
CATEGORIES=	fonts
MASTER_SITES=	https://go.googlesource.com/image/+archive/${COMMIT_ID}/font/gofont/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://blog.golang.org/go-fonts
COMMENT=	Family of high-quality WGL4 TrueType fonts created for the Go project
LICENSE=	modified-bsd

COMMIT_ID=	d2f07f8aaaa906f1a64eee0e327fc681cdb2944f
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
