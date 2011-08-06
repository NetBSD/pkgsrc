# $NetBSD: Makefile,v 1.16 2011/08/06 11:36:30 wiz Exp $
#

DISTNAME=	gaupol-0.19
CATEGORIES=	misc
MASTER_SITES=	http://download.gna.org/gaupol/0.19/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://home.gna.org/gaupol/index.html
COMMENT=	Subtitle editor
LICENSE=	gnu-gpl-v3

DEPENDS+=	iso-codes-[0-9]*:../../textproc/iso-codes
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-enchant>=1.4:../../textproc/py-enchant
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.16:../../x11/py-gtk2

PYTHON_VERSIONS_ACCEPTED=	27 26
PYDISTUTILSPKG= 		yes
USE_LANGUAGES=			# none
USE_TOOLS+=			intltool msgfmt
PKG_DESTDIR_SUPPORT=		user-destdir

PYSETUPARGS=		--mandir=${PREFIX}/${PKGMANDIR}

.include "../../lang/python/extension.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
