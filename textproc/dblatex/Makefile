# $NetBSD: Makefile,v 1.11 2012/03/15 11:53:40 obache Exp $
#

DISTNAME=	dblatex-0.3.2
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dblatex/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dblatex.sourceforge.net/
COMMENT=	DocBook to LaTeX Publishing
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX3-bin
DEPENDS+=	transfig-[0-9]*:../../print/transfig
DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	lib/dbtexmf/dblatex/xetex/*.py

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Fixing man page installation path.
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	setup.py
SUBST_SED.man+=		-e 's,share/man/man1,${PKGMANDIR}/man1,'
SUBST_SED.man+=		-e "s,'python','${PYTHONBIN}',"

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
