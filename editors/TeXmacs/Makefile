# $NetBSD: Makefile,v 1.45 2005/07/06 18:09:49 drochner Exp $

DISTNAME=	TeXmacs-1.0.5.5-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.texmacs.org/
COMMENT=	GNU TeXmacs (free scientific text editor)

DEPENDS+=	teTeX>=1.0:../../print/teTeX

BUILD_TARGET=	TEXMACS

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

PYTHON_PATCH_SCRIPTS=	plugins/python/bin/tm_python

SUBST_CLASSES+=		init
SUBST_STAGE.init=	post-patch
SUBST_FILES.init=	plugins/python/progs/init-python.scm
SUBST_SED.init=		-e 's,@PYTHONBIN@,${PYTHONBIN},g'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
