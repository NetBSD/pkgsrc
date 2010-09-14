# $NetBSD: Makefile,v 1.17 2010/09/14 11:01:19 wiz Exp $
#

DISTNAME=		bmp-musepack-1.2
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://files.musepack.net/linux/plugins/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.musepack.net/
COMMENT=		BMP plugin for Musepack (mpc) files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../audio/bmp/buildlink3.mk"
.include "../../audio/libmpcdec/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
