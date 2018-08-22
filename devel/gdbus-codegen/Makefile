# $NetBSD: Makefile,v 1.18 2018/08/22 09:43:30 wiz Exp $

PKGREVISION= 1
.include "../../devel/glib2/Makefile.common"

PKGNAME:=	${PKGNAME:S/glib2/gdbus-codegen/}
CATEGORIES=	devel gnome

COMMENT=	Generate code and/or documentation for one or more D-Bus interfaces

NOT_FOR_PLATFORM=	HPUX-*-* OSF1-*-*

USE_TOOLS+=		pkg-config msgfmt perl:run

BUILD_DIRS=		gio/gdbus-2.0/codegen
INSTALL_DIRS=		${BUILD_DIRS}

REPLACE_PYTHON+=	gio/gdbus-2.0/codegen/gdbus-codegen.in

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "../../devel/glib2/modules.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
