# $NetBSD: Makefile,v 1.1.1.1 2003/09/02 07:32:04 xtraeme Exp $
#

DISTNAME=	gossip-${VER}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gossip/${VER}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GTK2 Jabber Instant Messaging client

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

VER=			0.5

GCONF2_SCHEMAS=		gossip.schemas
LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/loudmouth/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../mk/bsd.pkg.mk"
