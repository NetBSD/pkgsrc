# $NetBSD: Makefile,v 1.5 2013/04/06 03:45:09 rodent Exp $

.include "../../devel/glib2/Makefile.common"

PKGNAME:=	${PKGNAME:S/glib2/gdbus-codegen/}
CATEGORIES=	sysutils

COMMENT=	Generate code and/or documentation for one or more D-Bus interfaces

NOT_FOR_PLATFORM=	HPUX-*-* OSF1-*-*

USE_TOOLS+=		pkg-config msgfmt perl:run

BUILD_DIRS=		gio/gdbus-2.0/codegen
INSTALL_DIRS=		${BUILD_DIRS}

REPLACE_PYTHON+=	gio/gdbus-2.0/codegen/gdbus-codegen.in

.include "../../devel/glib2/modules.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
