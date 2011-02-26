# $NetBSD: Makefile,v 1.7 2011/02/26 11:27:36 wiz Exp $
#

DISTNAME=	Inconsolata.otf
PKGNAME=	inconsolata-ttf-20090207
CATEGORIES=	fonts
MASTER_SITES=	http://www.levien.com/type/myfonts/
EXTRACT_SUFX=	# empty

MAINTAINER=	smb@NetBSD.org
HOMEPAGE=	http://www.levien.com/type/myfonts/inconsolata.html
COMMENT=	Inconsolata TrueType font
LICENSE=	open-font-license

PKG_DESTDIR_SUPPORT=	user-destdir

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
