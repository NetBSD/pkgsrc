# $NetBSD: Makefile,v 1.41 2018/11/14 22:21:01 kleink Exp $

DISTNAME=	bsl-0.5.0
PKGREVISION=	36
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buzztard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://buzztrax.org/
COMMENT=	Buzz song loader
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config
USE_LANGUAGES=	c c++

USE_PKGLOCALEDIR=	yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/bml/buildlink3.mk"
.include "../../audio/buzztard/buildlink3.mk"
.include "../../audio/gst-buzztard/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
