# $NetBSD: Makefile,v 1.10 2009/05/19 08:59:08 wiz Exp $
#

DISTNAME=	diffuse-0.3.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=diffuse/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://diffuse.sourceforge.net/
COMMENT=	Graphical tool for merging and comparing text files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
USE_DIRS=	xdg-1.4 gnome2-1.6

CONF_FILES+=	${PREFIX}/share/examples/diffuse/diffuserc \
		${PKG_SYSCONFDIR}/diffuserc

PYTHON_VERSIONS_ACCEPTED=	25 24

do-build:
	# nothing

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} ./install.py --destdir=/${DESTDIR} \
		--examplesdir=${PREFIX}/share/examples/diffuse \
		--mandir=${PREFIX}/${PKGMANDIR} \
		--prefix=${PREFIX} --sysconfdir=${PKG_SYSCONFDIR} \
		--pythonbin=${PYTHONBIN} --files-only

.include "../../lang/python/application.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.10
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
