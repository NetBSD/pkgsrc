# $NetBSD: Makefile,v 1.14 2004/01/23 21:50:43 jmmv Exp $
#

DISTNAME=	gossip-0.7
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gossip/0.7/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GTK2 Jabber Instant Messaging client

DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_DEPENDS=		p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=       yes
GNU_CONFIGURE=		yes

GCONF2_SCHEMAS=		gossip.schemas
LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/loudmouth/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../mk/bsd.pkg.mk"
