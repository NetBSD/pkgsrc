# $NetBSD: Makefile,v 1.2 2012/06/04 10:10:01 drochner Exp $

.include "../../devel/glib2/Makefile.common"

PKGNAME:=	${PKGNAME:S/glib2/gdbus-codegen/}
CATEGORIES=	sysutils

COMMENT=	gdbus-codegen utility

NOT_FOR_PLATFORM=	HPUX-*-* OSF1-*-*

USE_TOOLS+=		pkg-config

BUILD_DIRS=		gio/gdbus-2.0/codegen
INSTALL_DIRS=		${BUILD_DIRS}

REPLACE_PYTHON+=	gio/gdbus-2.0/codegen/gdbus-codegen.in

.include "../../devel/glib2/modules.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
