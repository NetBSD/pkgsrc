# $NetBSD: Makefile,v 1.2 2016/04/14 11:32:45 jperkin Exp $
#

DISTNAME=		gdmap-0.8.1
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
