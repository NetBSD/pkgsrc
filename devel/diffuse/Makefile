# $NetBSD: Makefile,v 1.48 2022/06/30 11:18:13 nia Exp $

DISTNAME=	diffuse-0.4.8
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=diffuse/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://diffuse.sourceforge.net/
COMMENT=	Graphical tool for merging and comparing text files
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.10:../../x11/py-gtk2
PYTHON_VERSIONS_ACCEPTED= 27 # py-gtk2

USE_TOOLS+=	msgfmt
USE_LANGUAGES=	# none

CONF_FILES+=	${PREFIX}/share/examples/diffuse/diffuserc \
		${PKG_SYSCONFDIR}/diffuserc

do-build:
	# nothing

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} ./install.py --destdir=/${DESTDIR} \
		--examplesdir=${PREFIX}/share/examples/diffuse \
		--mandir=${PREFIX}/${PKGMANDIR} \
		--prefix=${PREFIX} --sysconfdir=${PKG_SYSCONFDIR} \
		--pythonbin=${PYTHONBIN} --files-only

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
