# $NetBSD: Makefile,v 1.132 2024/11/16 12:03:13 wiz Exp $

PKGNAME=	libpurple-${PIDGIN_VERSION}
PKGREVISION=	4
#PKGREVISION=	0

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
