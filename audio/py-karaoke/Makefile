# $NetBSD: Makefile,v 1.9 2009/07/22 09:01:19 wiz Exp $
#

DISTNAME=	pykaraoke-0.6
PKGNAME=	${PYPKGPREFIX}-karaoke-0.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pykaraoke/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pykaraoke.sourceforge.net/
COMMENT=	Free Python-based karaoke player

PKG_DESTDIR_SUPPORT=	user-destdir

# for .kar files, untested for lack of files
#DEPENDS+=	timidity-[0-9]*:../../audio/timidity

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
