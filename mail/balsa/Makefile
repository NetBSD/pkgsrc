# $NetBSD: Makefile,v 1.162 2020/11/05 09:08:34 ryoon Exp $

DISTNAME=	balsa-2.6.1
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	https://pawsa.fedorapeople.org/balsa/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pawsa.fedorapeople.org/balsa/
COMMENT=	Email client using GTK3
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake intltool perl pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

TOOL_DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
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
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
