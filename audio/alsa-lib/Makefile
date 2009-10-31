# $NetBSD: Makefile,v 1.6 2009/10/31 02:36:10 wiz Exp $
#

DISTNAME=	alsa-lib-1.0.21a
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alsa-project.org/
COMMENT=	Advanced Linux Sound Architecture (ALSA)
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	utils/alsa.pc.in

CONFIGURE_ARGS+=	--disable-python

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
