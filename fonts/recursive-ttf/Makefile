# $NetBSD: Makefile,v 1.7 2021/12/29 11:49:49 rhialto Exp $

GITHUB_PROJECT=	recursive
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
DISTNAME=	ArrowType-Recursive-${PKGVERSION_NOREV}
PKGNAME=	recursive-ttf-1.084
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=arrowtype/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.recursive.design/
COMMENT=	Variable font family for code & UI
LICENSE=	ofl-v1.1

# \todo: Build from source.
# \todo: Install even more of the fonts? woff?

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/Recursive_Desktop/separate_statics/OTF
WRKSRC2=	${WRKDIR}/${DISTNAME}/Recursive_Code

FONTS_DIRS.ttf+=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf+=	${PREFIX}/share/fonts/X11/OTF

.PHONY: install-fonts2

do-install: install-fonts2

install-fonts2:
	@${STEP_MSG} "Installing all .ttf files from ${WRKSRC2}"
	${FIND} ${WRKSRC2} -name ${DESTDIR:T} -prune -o -iname '*.ttf' -exec \
	        ${INSTALL_DATA} "{}" ${DESTDIR}${TTF_FONTS_DIR} ";"

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
