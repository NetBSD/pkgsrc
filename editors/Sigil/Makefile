# $NetBSD: Makefile,v 1.10 2010/02/16 15:37:05 wiz Exp $
#

DISTNAME=	Sigil-0.1.9-Code
PKGNAME=	${DISTNAME:S/-Code//}
CATEGORIES=	editors
MASTER_SITES=	http://sigil.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sigil/
COMMENT=	Multi-platform WYSIWYG ebook editor (for the ePub format)
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
