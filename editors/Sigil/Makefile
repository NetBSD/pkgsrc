# $NetBSD: Makefile,v 1.4 2009/08/26 19:57:25 sno Exp $
#

DISTNAME=	Sigil_code_0.1.2
PKGNAME=	${DISTNAME:S/_code_/-/}
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://sigil.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sigil/
COMMENT=	Multi-platform WYSIWYG ebook editor (for the ePub format)
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin libexec/Sigil/data

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
