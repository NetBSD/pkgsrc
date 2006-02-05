# $NetBSD: Makefile,v 1.16 2006/02/05 23:11:01 joerg Exp $
#

DISTNAME=		enchant-1.1.6
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		http://www.abisource.com/downloads/enchant/1.1.6/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.abisource.com/enchant/
COMMENT=		Generic spell checking library

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes
CFLAGS.SunOS+=		-D__EXTENSIONS__

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
