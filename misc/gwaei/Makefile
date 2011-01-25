# $NetBSD: Makefile,v 1.16 2011/01/25 11:02:34 ryoon Exp $
#

DISTNAME=	gwaei-1.5.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwaei/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gwaei.sourceforge.net/
COMMENT=	Japanese dictionary for GNOME
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl pkg-config

PLIST_SRC=		PLIST

.include "options.mk"

INSTALLATION_DIRS=	share/glib-2.0/schemas

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/schemas/*xml \
	    ${DESTDIR}${PREFIX}/share/glib-2.0/schemas/

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.5
.include "../../devel/glib2/schemas.mk"
BUILDLINK_API_DEPENDS.curl+=	curl>=7.18.0
.include "../../www/curl/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.14.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
