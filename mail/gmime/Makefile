# $NetBSD: Makefile,v 1.11 2006/02/05 23:09:55 joerg Exp $
#

DISTNAME=	gmime-2.1.9
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://spruce.sourceforge.net/gmime/sources/v2.1/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://spruce.sourceforge.net/gmime/
COMMENT=	Library for the creation and parsing of MIME messages

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
PKGCONFIG_OVERRIDE+=	gmime-2.0.pc.in

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
