# $NetBSD: Makefile,v 1.10 2013/04/08 01:42:40 rodent Exp $
#

DISTNAME=	Inconsolata.otf
PKGNAME=	inconsolata-ttf-20090207
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

INSTALLATION_DIRS=	lib/X11/fonts/TTF
FONTS_DIRS.ttf=		${PREFIX}/lib/X11/fonts/TTF

do-extract:
	${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${DESTDIR}${PREFIX}/lib/X11/fonts/TTF

.include "../../mk/bsd.pkg.mk"
