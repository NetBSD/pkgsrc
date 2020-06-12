# $NetBSD: Makefile,v 1.100 2020/06/12 11:40:19 nia Exp $

PKGNAME=	libpurple-${PIDGIN_VERSION}

COMMENT=	Multi-protocol Instant Messaging client backend

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
