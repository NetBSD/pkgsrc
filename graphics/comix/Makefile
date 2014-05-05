# $NetBSD: Makefile,v 1.50 2014/05/05 00:47:55 ryoon Exp $

DISTNAME=		comix-4.0.4
PKGREVISION=		26
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=comix/}

MAINTAINER=		hugor@users.sourceforge.net
HOMEPAGE=		http://comix.sourceforge.net/index.html
COMMENT=		Image viewer specifically designed to handle comic books
LICENSE=		gnu-gpl-v2

DEPENDS+=		unrar-[0-9]*:../../archivers/unrar
DEPENDS+=		${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

MANCOMPRESSED=		yes

.include "options.mk"

SUBST_CLASSES+=			install-path
SUBST_STAGE.install-path=	pre-build
SUBST_MESSAGE.install-path=	Fixing man page installation path.
SUBST_FILES.install-path=	install.py
SUBST_SED.install-path=		-e "s,share/man/man,${PKGMANDIR}/man,g"

REPLACE_PYTHON=			src/comix.py mime/comicthumb
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-imaging, py-gtk2

do-build:

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} install.py install --dir ${DESTDIR}${PREFIX}

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.5
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.12
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
