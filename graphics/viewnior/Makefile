# $NetBSD: Makefile,v 1.28 2018/11/14 22:21:47 kleink Exp $
#

DISTNAME=	viewnior-1.3
PKGREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	https://cloud.github.com/downloads/xsisqox/Viewnior/

MAINTAINER=	ryoon@NetBSD.org
#HOMEPAGE=	http://xsisqox.github.com/Viewnior/
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
