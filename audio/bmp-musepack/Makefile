# $NetBSD: Makefile,v 1.29 2013/02/16 11:20:05 wiz Exp $
#

DISTNAME=		bmp-musepack-1.2
PKGREVISION=		14
CATEGORIES=		audio
MASTER_SITES=		http://files.musepack.net/linux/plugins/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.musepack.net/
COMMENT=		BMP plugin for Musepack (mpc) files

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../audio/bmp/buildlink3.mk"
.include "../../audio/libmpcdec/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
