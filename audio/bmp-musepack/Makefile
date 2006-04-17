# $NetBSD: Makefile,v 1.9 2006/04/17 13:46:15 wiz Exp $
#

DISTNAME=		bmp-musepack-1.1
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://www.saunalahti.fi/grimmel/musepack.net/linux/plugins/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.musepack.net/
COMMENT=		BMP plugin for Musepack (mpc) files

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../audio/bmp/buildlink3.mk"
.include "../../audio/libmusepack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
