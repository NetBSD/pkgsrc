# $NetBSD: Makefile,v 1.63 2024/05/29 16:32:24 adam Exp $

DISTNAME=	medit-1.2.0
PKGREVISION=	31
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mooedit/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mooedit.sourceforge.net/index.html
COMMENT=	Programming and around-programming text editor
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config msgfmt intltool

PYTHON_FOR_BUILD_ONLY=		yes
PYTHON_VERSIONS_INCOMPATIBLE+=	27
CONFIGURE_ARGS+=		--with-python=no
CONFIGURE_ENV+=			MOO_PYTHON=${PYTHONBIN}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
