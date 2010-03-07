# $NetBSD: Makefile,v 1.7 2010/03/07 08:56:55 wiz Exp $
#

DISTNAME=	gaupol-0.15
CATEGORIES=	misc
MASTER_SITES=	http://download.gna.org/gaupol/0.15/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://home.gna.org/gaupol/index.html
COMMENT=	Subtitle editor

DEPENDS+=	iso-codes-[0-9]*:../../textproc/iso-codes
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-enchant>=1.1.3:../../textproc/py-enchant
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.12:../../x11/py-gtk2

PYTHON_VERSIONS_ACCEPTED=	26 25
PYDISTUTILSPKG= 		yes
USE_LANGUAGES=			# none
USE_TOOLS+=			intltool msgfmt
PKG_DESTDIR_SUPPORT=		user-destdir

SUBST_CLASSES+=			manpath
SUBST_FILES.manpath=		INSTALL setup.py
SUBST_MESSAGE.manpath=		Fixing man page installation path.
SUBST_SED.manpath=		-e "s,share/man/man1,${PKGMANDIR}/man1,"
SUBST_STAGE.manpath=		pre-build

.include "../../lang/python/extension.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
