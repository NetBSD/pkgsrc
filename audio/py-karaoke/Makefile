# $NetBSD: Makefile,v 1.13 2010/02/10 11:37:21 wiz Exp $
#

DISTNAME=	pykaraoke-0.7.2
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

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

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
.include "../../audio/py-mutagen/buildlink3.mk"
.include "../../devel/py-game/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
