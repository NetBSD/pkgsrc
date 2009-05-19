# $NetBSD: Makefile,v 1.20 2009/05/19 08:59:16 wiz Exp $
#

DISTNAME=		comix-4.0.4
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=comix/}

MAINTAINER=		hugor@users.sourceforge.net
HOMEPAGE=		http://comix.sourceforge.net/index.html
COMMENT=		Image viewer specifically designed to handle comic books
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		unrar-[0-9]*:../../archivers/unrar
.include "../../lang/python/extension.mk"
.if ${PYPKGPREFIX} == "py24"
.include "../../databases/py-sqlite2/buildlink3.mk"
.else
DEPENDS+=		${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
.endif

USE_DIRS+=		xdg-1.3
MANCOMPRESSED=		yes

SUBST_CLASSES+=			install-path
SUBST_STAGE.install-path=	pre-build
SUBST_MESSAGE.install-path=	Fixing man page installation path.
SUBST_FILES.install-path=	install.py
SUBST_SED.install-path=		-e "s,share/man/man,${PKGMANDIR}/man,g"

PYTHON_PATCH_SCRIPTS=		src/comix.py mime/comicthumb

do-build:

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} install.py install --dir ${DESTDIR}${PREFIX}

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.5
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.12
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
