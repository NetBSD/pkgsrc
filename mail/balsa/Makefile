# $NetBSD: Makefile,v 1.154 2020/04/12 08:28:55 adam Exp $

DISTNAME=	balsa-2.5.9
PKGREVISION=	4
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

CFLAGS.SunOS+=	-D__EXTENSIONS__

CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--with-html-widget=no
CONFIGURE_ARGS+=	--with-gpgme
CONFIGURE_ARGS+=	--with-libsecret
CONFIGURE_ARGS+=	--with-gtksourceview

.include "options.mk"
.include "../../mail/gmime/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
