# $NetBSD: Makefile,v 1.1 2017/10/13 15:44:29 prlw1 Exp $

.include "../../devel/glib2/Makefile.common"

PKGNAME:=	${PYPKGPREFIX}-${PKGNAME:S/glib2/glib2-tools/}
CATEGORIES=	devel gnome

COMMENT=	GLib2 python-dependent tools

NOT_FOR_PLATFORM=	HPUX-*-* OSF1-*-*

USE_TOOLS+=		pkg-config msgfmt perl:run

DISTINFO_FILE=          ${.CURDIR}/distinfo
PATCHDIR=		${.CURDIR}/patches

BUILD_DIRS=		gio/gdbus-2.0/codegen

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

do-install:
	cd ${WRKSRC} \
	&& cd gio/gdbus-2.0/codegen \
	&& env ${MAKE_ENV} ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} install
	cd ${WRKSRC} \
	&& cd gobject \
	&& env ${MAKE_ENV} ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} install-binSCRIPTS

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
