# $NetBSD: Makefile,v 1.1.1.1 2001/06/17 19:13:52 drochner Exp $
#

DISTNAME=	audacity-src-0.95
PKGNAME=	audacity-0.95
CATEGORIES=	audio
MASTER_SITES=	http://prdownloads.sourceforge.net/audacity/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.cmu.edu/~music/audacity/
COMMENT=	audio editor

DEPENDS+=	wxGTK-*:../../x11/wxGTK
BUILD_DEPENDS+=	zip-*:../../archivers/zip

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-xaudio --with-libmpeg3
USE_GMAKE=	yes

post-patch:
	${SED} "s|XXXHELPDIRXXX|${PREFIX}/share|" \
		<${WRKSRC}/Help.cpp >${WRKSRC}/Help.cpp.tmp \
	&& ${MV} ${WRKSRC}/Help.cpp.tmp ${WRKSRC}/Help.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/audacity ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/audacity-help.htb ${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
