# $NetBSD: Makefile,v 1.5 2005/08/10 20:56:11 jlam Exp $
#

DISTNAME=		bmp-musepack-1.1
CATEGORIES=		audio
MASTER_SITES=		http://www.saunalahti.fi/grimmel/musepack.net/linux/plugins/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.musepack.net/
COMMENT=		BMP plugin for Musepack (mpc) files

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../audio/bmp/buildlink3.mk"
.include "../../audio/libmusepack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
