# $NetBSD: Makefile,v 1.1 2012/06/04 09:57:42 drochner Exp $

.include "../../devel/glib2/Makefile.common"

PKGNAME:=	${PKGNAME:S/glib2/gdbus-godegen/}
CATEGORIES=	sysutils

COMMENT=	gdbus-godegen utility

NOT_FOR_PLATFORM=	HPUX-*-* OSF1-*-*

USE_TOOLS+=		pkg-config

BUILD_DIRS=		gio/gdbus-2.0/codegen
INSTALL_DIRS=		${BUILD_DIRS}

REPLACE_PYTHON+=	gio/gdbus-2.0/codegen/gdbus-codegen.in

.include "../../devel/glib2/modules.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
