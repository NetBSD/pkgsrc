# $NetBSD: Makefile,v 1.14 2005/07/21 16:29:58 wiz Exp $
#

DISTNAME=		enchant-1.1.6
CATEGORIES=		textproc
MASTER_SITES=		http://www.abisource.com/downloads/enchant/1.1.6/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.abisource.com/enchant/
COMMENT=		Generic spell checking library

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes
CFLAGS.SunOS+=		-D__EXTENSIONS__

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
