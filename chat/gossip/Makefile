# $NetBSD: Makefile,v 1.30 2004/10/03 00:13:14 tv Exp $
#

DISTNAME=	gossip-0.7.8
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gossip/0.7/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gossip.imendio.org/
COMMENT=	GTK2 Jabber Instant Messaging client

BUILD_DEPENDS=		p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=       yes
GNU_CONFIGURE=		yes

GCONF2_SCHEMAS=		gossip.schemas

.include "../../chat/loudmouth/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
