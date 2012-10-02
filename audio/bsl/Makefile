# $NetBSD: Makefile,v 1.17 2012/10/02 17:10:30 tron Exp $
#

DISTNAME=	bsl-0.5.0
PKGREVISION=	14
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buzztard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://buzztard.sourceforge.net/
COMMENT=	Buzz song loader
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config
USE_LANGUAGES=	c c++

USE_PKGLOCALEDIR=	yes

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../audio/gst-buzztard/buildlink3.mk"
.include "../../audio/buzztard/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
