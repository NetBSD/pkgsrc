# $NetBSD: Makefile,v 1.11 2018/11/14 22:22:24 kleink Exp $
#

DISTNAME=		gdmap-0.8.1
PKGREVISION=		9
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gdmap/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://gdmap.sourceforge.net/
COMMENT=		Tool to visualize disk space
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config msgfmt xgettext perl intltool

LDFLAGS.SunOS+=		-lm

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
