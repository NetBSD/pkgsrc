# $NetBSD: Makefile,v 1.68 2012/09/07 19:16:29 adam Exp $

DISTNAME=	dasher-4.10.1
PKGREVISION=	16
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dasher/4.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.inference.phy.cam.ac.uk/dasher/
COMMENT=	Easy typing without using keyboard
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	${GCONF_SCHEMAS_DIR}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly"
# Needed for ftime(3).
LIBS+=			-lcompat
.endif

GCONF_SCHEMAS+=	dasher.schemas

post-build:
	cd ${WRKSRC}/Data && ../Src/Gtk2/generate-schema >dasher.schemas

post-install:
	${INSTALL_DATA} ${WRKSRC}/Data/dasher.schemas ${DESTDIR}${GCONF_SCHEMAS_DIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
