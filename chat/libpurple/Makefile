# $NetBSD: Makefile,v 1.112 2021/11/15 22:53:55 wiz Exp $

PKGNAME=	libpurple-${PIDGIN_VERSION}
PKGREVISION=	3

COMMENT=	Plugin-based multi-protocol instant messaging library

.include		"../../chat/libpurple/Makefile.common"

USE_TOOLS+=		intltool msgfmt msgmerge xgettext

CPPFLAGS.SunOS+=	-D__SunOS

.include "options.mk"

BUILD_DIRS=	m4macros libpurple po share/ca-certs share/sounds

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
