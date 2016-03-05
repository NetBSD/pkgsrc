# $NetBSD: Makefile,v 1.10 2016/03/05 09:40:53 ryoon Exp $

DISTNAME=	corebird-1.2
CATEGORIES=	net
MASTER_SITES=	-https://github.com/baedert/corebird/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://corebird.baedert.org/
COMMENT=	Native Gtk+ Twitter Client
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	yes
USE_LANGUAGES=	c
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	autogen.sh
USE_TOOLS+=	autoconf automake intltool gettext-m4 pkg-config gmake msgfmt

.include "options.mk"

TEST_TARGET=	check

.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../www/librest07/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala=	build
.include "../../lang/vala/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../mk/bsd.pkg.mk"
