# $NetBSD: Makefile,v 1.6 2008/04/25 20:39:06 joerg Exp $
#

DISTNAME=	pykaraoke-0.5.1
PKGNAME=	${PYPKGPREFIX}-karaoke-0.5.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pykaraoke/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pykaraoke.sourceforge.net/
COMMENT=	Free Python-based karaoke player

# for .kar files, untested for lack of files
#DEPENDS+=	timidity-[0-9]*:../../audio/timidity

USE_DIRS+=	xdg-1.4
PYTHON_VERSIONS_ACCEPTED=	25 24
PYDISTUTILSPKG=	yes

# supposedly needed, but I couldn't find out why
#.include "../../audio/SDL_mixer/buildlink3.mk"
#.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/py-game/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
