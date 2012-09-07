# $NetBSD: Makefile,v 1.47 2012/09/07 19:17:06 adam Exp $

DISTNAME=	qalculate-gtk-0.9.7
PKGREVISION=	14
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qalculate/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://qalculate.sourceforge.net/
COMMENT=	Modern multi-purpose desktop calculator (GNOME version)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC}; autoconf

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../math/qalculate/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
