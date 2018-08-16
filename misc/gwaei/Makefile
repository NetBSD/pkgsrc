# $NetBSD: Makefile,v 1.61 2018/08/16 18:55:00 adam Exp $
#

DISTNAME=	gwaei-3.6.2
PKGREVISION=	18
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwaei/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zakkudo/gwaei
COMMENT=	Japanese dictionary for GNOME
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config

PLIST_SRC=		PLIST

.include "options.mk"

INSTALLATION_DIRS=	share/glib-2.0/schemas

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/schemas/*xml \
	    ${DESTDIR}${PREFIX}/share/glib-2.0/schemas/

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.31.0
.include "../../devel/glib2/schemas.mk"
BUILDLINK_API_DEPENDS.curl+=	curl>=7.20.0
.include "../../www/curl/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.3.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc/mecab-base/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
