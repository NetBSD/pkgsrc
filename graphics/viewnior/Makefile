# $NetBSD: Makefile,v 1.16 2013/09/02 19:51:10 adam Exp $
#

DISTNAME=	viewnior-1.3
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://cloud.github.com/downloads/xsisqox/Viewnior/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://xsisqox.github.com/Viewnior/
COMMENT=	Viewnior is a fast and simple image viewer
LICENSE=	gnu-gpl-v3

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	intltool pkg-config gmake msgfmt

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
