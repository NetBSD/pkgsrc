# $NetBSD: Makefile,v 1.31 2004/07/03 21:25:53 recht Exp $

DISTNAME=	TeXmacs-1.0.3.10-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.texmacs.org/
COMMENT=	GNU TeXmacs (free scientific text editor)

DEPENDS+=	teTeX>=1.0:../../print/teTeX

ALL_TARGET=	TEXMACS

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PKG_CXXFLAGS=${CXXFLAGS:Q}
CONFIGURE_ENV+=		PKG_LDFLAGS=${LDFLAGS:Q}

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
