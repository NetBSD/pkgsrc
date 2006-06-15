# $NetBSD: Makefile,v 1.18 2006/06/15 13:31:30 wiz Exp $
#

DISTNAME=		enchant-1.1.6
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		http://www.abisource.com/downloads/enchant/1.1.6/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.abisource.com/enchant/
COMMENT=		Generic spell checking library

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes
CFLAGS.SunOS+=		-D__EXTENSIONS__

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
