# $NetBSD: Makefile,v 1.3 2009/01/28 05:38:53 obache Exp $
#

DISTNAME=	alsa-lib-1.0.18
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alsa-project.org/
COMMENT=	Advanced Linux Sound Architecture (ALSA)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	utils/alsa.pc.in

CONFIGURE_ARGS+=	--disable-python

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
