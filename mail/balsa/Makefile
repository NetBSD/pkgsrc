# $NetBSD: Makefile,v 1.183 2023/11/14 14:02:24 wiz Exp $

DISTNAME=	balsa-2.6.3
PKGREVISION=	14
CATEGORIES=	mail
MASTER_SITES=	https://pawsa.fedorapeople.org/balsa/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pawsa.fedorapeople.org/balsa/
COMMENT=	Email client using GTK3
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake intltool perl pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext itstool
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

TOOL_DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	yelp-tools-[0-9]*:../../textproc/yelp-tools

CFLAGS.SunOS+=	-D__EXTENSIONS__

CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--with-canberra
CONFIGURE_ARGS+=	--with-html-widget=no
CONFIGURE_ARGS+=	--with-libsecret
CONFIGURE_ARGS+=	--with-gtksourceview
CONFIGURE_ARGS+=	--with-sqlite

.include "options.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mail/gmime3/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtksourceview4/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
