# $NetBSD: Makefile,v 1.41 2014/05/05 00:48:09 ryoon Exp $
#

DISTNAME=	gwaei-3.0.2
PKGREVISION=	19
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwaei/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gwaei.sourceforge.net/
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
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.25.0
.include "../../devel/glib2/schemas.mk"
BUILDLINK_API_DEPENDS.curl+=	curl>=7.19.6
.include "../../www/curl/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.0.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
