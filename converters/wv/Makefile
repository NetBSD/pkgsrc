# $NetBSD: Makefile,v 1.17 2001/12/10 14:30:14 taca Exp $
#

DISTNAME=		wv-0.7.0
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.wvWare.com/
COMMENT=		Microsoft Word 6, 7, 8, and 9 (95/97/2000) doc to HTML/LaTeX converter

# not detected by configure, causes conflicts with the one coming with wv
#CONFLICTS+=		libgetopt-[0-9]*

USE_BUILDLINK_ONLY=	YES
REPLACE_BUILDLINK=	wv-incconfig wv-libconfig

USE_GMAKE=		YES
GNU_CONFIGURE=		YES
MAKE_ENV+=		RM="${RM} -f"

post-install:
	${TOUCH} ${PREFIX}/share/wv/ttf/.directory
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wv
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING CREDITS INSTALL KNOWN-BUGS \
		README help/Docs/XML_Tags ${PREFIX}/share/doc/wv

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../graphics/ImageMagick/buildlink.mk"
.include "../../graphics/libwmf/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
