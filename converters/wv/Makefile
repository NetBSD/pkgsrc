# $NetBSD: Makefile,v 1.20 2002/09/11 11:23:14 wiz Exp $
#

DISTNAME=		wv-0.7.2
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.wvWare.com/
COMMENT=		Microsoft Word 6, 7, 8, and 9 (95/97/2000) doc to HTML/LaTeX converter

# not detected by configure, causes conflicts with the one coming with wv
#CONFLICTS+=		libgetopt-[0-9]*

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
MAKE_ENV+=		RM="${RM} -f"

post-install:
	${TOUCH} ${PREFIX}/share/wv/ttf/.directory
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wv
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING CREDITS INSTALL KNOWN-BUGS \
		README help/Docs/XML_Tags ${PREFIX}/share/doc/wv

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../graphics/libwmf/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
