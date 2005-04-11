# $NetBSD: Makefile,v 1.3 2005/04/11 21:44:51 tv Exp $
#

DISTNAME=		bmp-musepack-1.1
CATEGORIES=		audio
MASTER_SITES=		http://www.saunalahti.fi/grimmel/musepack.net/linux/plugins/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.musepack.net/
COMMENT=		BMP plugin for Musepack (mpc) files

GNU_CONFIGURE=		yes

.include "../../audio/bmp/buildlink3.mk"
.include "../../audio/libmusepack/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
