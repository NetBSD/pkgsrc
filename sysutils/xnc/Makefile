# $NetBSD: Makefile,v 1.46 2023/08/02 19:21:57 nia Exp $

DISTNAME=	xnc-5.0.4.src
PKGNAME=	xnc-5.0.4
PKGREVISION=	14
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.xnc.dubna.su/src-5/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://xnc.dubna.su/
COMMENT=	File manager for X Window
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt
GNU_CONFIGURE=	yes

# Fails with C++14 default language
FORCE_CXX_STD=	c++03

# editor.cxx: In member function 'char Editor::trans(int, char)':
# editor.cxx:624:15: error: array subscript has type 'char' [-Werror=char-subscripts]
#    sym=rtbl[sym];
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
