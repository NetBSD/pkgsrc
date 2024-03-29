# $NetBSD: Makefile,v 1.90 2023/11/14 14:02:00 wiz Exp $

DISTNAME=		comix-4.0.4
PKGREVISION=		55
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=comix/}

MAINTAINER=		hugor@users.sourceforge.net
HOMEPAGE=		http://comix.sourceforge.net/index.html
COMMENT=		Image viewer specifically designed to handle comic books
LICENSE=		gnu-gpl-v2

DEPENDS+=		unrar-[0-9]*:../../archivers/unrar

MANCOMPRESSED=		yes

.include "options.mk"

SUBST_CLASSES+=			install-path
SUBST_STAGE.install-path=	pre-build
SUBST_MESSAGE.install-path=	Fixing man page installation path.
SUBST_FILES.install-path=	install.py
SUBST_SED.install-path=		-e "s,share/man/man,${PKGMANDIR}/man,g"

REPLACE_PYTHON=			src/comix.py mime/comicthumb
PYTHON_VERSIONS_ACCEPTED=	27 # py-imaging, py-gtk2

do-build:

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} install.py install --dir ${DESTDIR}${PREFIX}

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.5
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.12
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
