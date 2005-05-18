# $NetBSD: Makefile,v 1.41 2005/05/18 15:37:46 drochner Exp $

DISTNAME=	TeXmacs-1.0.5.1-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.texmacs.org/
COMMENT=	GNU TeXmacs (free scientific text editor)

DEPENDS+=	teTeX>=1.0:../../print/teTeX

BUILD_TARGET=	TEXMACS

USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_X11=		yes
GNU_CONFIGURE=		yes

PYTHON_PATCH_SCRIPTS=	plugins/python/bin/tm_python

SUBST_CLASSES+=		init
SUBST_STAGE.init=	post-patch
SUBST_FILES.init=	plugins/python/progs/init-python.scm
SUBST_SED.init=		-e 's,@PYTHONBIN@,${PYTHONBIN},g'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
