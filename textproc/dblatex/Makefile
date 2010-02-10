# $NetBSD: Makefile,v 1.6 2010/02/10 19:17:46 joerg Exp $
#

DISTNAME=	dblatex-0.2.10
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dblatex/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dblatex.sourceforge.net/
COMMENT=	DocBook to LaTeX Publishing

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX3-bin
DEPENDS+=	transfig-[0-9]*:../../print/transfig
DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex

PYDISTUTILSPKG=	yes
USE_LANGUAGES=	# none

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Fixing man page installation path.
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	setup.py
SUBST_SED.man+=		-e 's,share/man/man1,${PKGMANDIR}/man1,'
SUBST_SED.man+=		-e "s,'python','${PYTHONBIN}',"

#SUBST_CLASSES+=		path
#SUBST_MESSAGE.path=	Fixing python path.
#SUBST_STAGE.path=	pre-configure
#SUBST_FILES.path=	scripts/dblatex
#SUBST_SED.path=         -e 's,/usr/bin/env python,${PYTHONBIN},g'

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
