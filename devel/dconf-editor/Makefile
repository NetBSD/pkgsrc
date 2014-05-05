# $NetBSD: Makefile,v 1.27 2014/05/05 00:47:43 ryoon Exp $

.include "../../devel/dconf/Makefile.common"

PKGNAME=	${DISTNAME:S/dconf/dconf-editor/}
PKGREVISION=	2

DISTINFO_FILE=	${.CURDIR}/../../devel/dconf/distinfo
PATCHDIR=	${.CURDIR}/../../devel/dconf/patches

CONFIGURE_ARGS+= --enable-editor
CONFIGURE_ARGS+= --disable-man

BUILD_DIRS=	editor
INSTALL_DIRS=	editor

SUBST_CLASSES+=	prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	editor/dconf-model.vala
SUBST_VARS.prefix=	PREFIX

# SUBST doesn't touch - force rebuild
pre-build:
	${RM} ${WRKSRC}/editor/dconf-model.c

.include "../../devel/glib2/schemas.mk"
BUILDLINK_DEPMETHOD.vala= build
.include "../../lang/vala018/buildlink3.mk"
BUILDLINK_API_DEPENDS.dconf+=	dconf>=${PKGVERSION_NOREV}
.include "../../devel/dconf/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
