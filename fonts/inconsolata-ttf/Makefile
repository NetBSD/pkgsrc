# $NetBSD: Makefile,v 1.1 2007/08/22 15:16:36 smb Exp $
#

DISTNAME=	Inconsolata.otf
PKGNAME=	inconsolata-20070822
CATEGORIES=	fonts
MASTER_SITES=	http://www.levien.com/type/myfonts/
EXTRACT_SUFX=	# empty

MAINTAINER=	smb@NetBSD.org
HOMEPAGE=	http://www.levien.com/type/myfonts/inconsolata.html
COMMENT=	Inconsolata TrueType font

#LICENSE=	sil-open-font-license

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

INSTALLATION_DIRS=	lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${PREFIX}/${INSTALLATION_DIRS:Q}

do-extract:
	${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${DESTDIR}${PREFIX}/${INSTALLATION_DIRS:Q}/

.include "../../mk/bsd.pkg.mk"
