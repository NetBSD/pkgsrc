# $NetBSD: Makefile,v 1.3 2008/09/22 23:36:54 jmcneill Exp $

DISTNAME=	ptlib-2.4.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/ptlib/2.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ekiga.net/
COMMENT=	Portable Windows Libary

CONFLICTS+=	pwlib-[0-9]*

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

USE_TOOLS+=		gmake tar pkg-config
BUILD_TARGET=		optshared
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--enable-oss
CONFIGURE_ARGS+=	--enable-v4l2
CONFIGURE_ARGS+=	--enable-opal
CONFIGURE_ARGS+=	--enable-openldap
#CONFIGURE_ARGS+=	--enable-openssl
CONFIGURE_ARGS+=	--enable-expat
#CONFIGURE_ARGS+=	--enable-samples
CONFIGURE_ARGS+=	--disable-bsdvideo
CONFIGURE_ARGS+=	--disable-sunaudio
CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-avc
CONFIGURE_ARGS+=	--disable-dc
PTHREAD_OPTS+=		require

post-install:
	${INSTALL_DATA} ${WRKSRC}/version.h ${PREFIX}/share/ptlib

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/libv4l/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
