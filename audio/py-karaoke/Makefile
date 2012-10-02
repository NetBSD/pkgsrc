# $NetBSD: Makefile,v 1.23 2012/10/02 23:48:05 asau Exp $
#

DISTNAME=	pykaraoke-0.7.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pykaraoke/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pykaraoke.sourceforge.net/
COMMENT=	Free Python-based karaoke player
LICENSE=	gnu-lgpl-v2.1

# for .kar files, untested for lack of files
#DEPENDS+=	timidity-[0-9]*:../../audio/timidity
DEPENDS+=	${PYPKGPREFIX}-wxWidgets>=2.6:../../x11/py-wxWidgets
DEPENDS+=	${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-Numeric-[0-9]*:../../math/py-Numeric

REPLACE_PYTHON+=	performer_prompt.py
REPLACE_PYTHON+=	pycdg.py
REPLACE_PYTHON+=	pykar.py
REPLACE_PYTHON+=	install/pykaraoke_mini
REPLACE_PYTHON+=	install/pympg
REPLACE_PYTHON+=	install/pykar
REPLACE_PYTHON+=	install/pykaraoke
REPLACE_PYTHON+=	install/pycdg
REPLACE_PYTHON+=	pykaraoke.py
REPLACE_PYTHON+=	setup.py
REPLACE_PYTHON+=	pympg.py
REPLACE_PYTHON+=	pykaraoke_mini.py

# supposedly needed, but I couldn't find out why
#.include "../../audio/SDL_mixer/buildlink3.mk"
#.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/py-game/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
