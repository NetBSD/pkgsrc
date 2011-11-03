# $NetBSD: Makefile,v 1.29 2011/11/03 00:22:23 wiz Exp $
#

DISTNAME=	diffuse-0.4.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=diffuse/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://diffuse.sourceforge.net/
COMMENT=	Graphical tool for merging and comparing text files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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

.include "../../lang/python/application.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.10
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
