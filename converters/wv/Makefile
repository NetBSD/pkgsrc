# $NetBSD: Makefile,v 1.11 2001/07/13 04:49:10 kei Exp $
#

DISTNAME=		wv-0.6.5
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.wvWare.com/
COMMENT=		Microsoft Word 6, 7, 8, and 9 (95/97/2000) doc to HTML/LaTeX converter

# not detected by configure, causes conflicts with the one coming with wv
#CONFLICTS+=		libgetopt-*

USE_BUILDLINK_ONLY=	YES
USE_X11=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

EVAL_PREFIX=		XPMDIR=xpm
MAKE_ENV+=		RM="${RM} -f"

post-install:
	${TOUCH} ${PREFIX}/share/wv/ttf/.directory
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wv
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING CREDITS INSTALL KNOWN-BUGS \
		README help/Docs/XML_Tags ${PREFIX}/share/doc/wv

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../graphics/libwmf/buildlink.mk"
.include "../../graphics/ImageMagick/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
