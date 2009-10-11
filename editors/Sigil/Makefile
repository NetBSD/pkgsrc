# $NetBSD: Makefile,v 1.5 2009/10/11 08:33:39 wiz Exp $
#

DISTNAME=	Sigil_code_0.1.3
PKGNAME=	${DISTNAME:S/_code_/-/}
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
