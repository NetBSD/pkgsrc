# $NetBSD: Makefile,v 1.11 2014/06/01 16:35:34 wiz Exp $
#

DISTNAME=	Inconsolata.otf
PKGNAME=	inconsolata-ttf-20090207
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.levien.com/type/myfonts/
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.levien.com/type/myfonts/inconsolata.html
COMMENT=	Inconsolata TrueType font
LICENSE=	ofl-v1.1

CONFLICTS=	inconsolata-[0-9]*

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	YES
NO_BUILD=	YES

INSTALLATION_DIRS=	share/fonts/X11/TTF
FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/TTF

do-extract:
	${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${DESTDIR}${PREFIX}/share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"
