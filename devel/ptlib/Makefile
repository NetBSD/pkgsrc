# $NetBSD: Makefile,v 1.18 2012/12/16 01:52:11 obache Exp $

DISTNAME=	ptlib-2.10.7
PKGREVISION= 2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/ptlib/2.10/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.ekiga.net/
COMMENT=	Portable Windows Libary
# modified-bsd stands for Spencer's regex license, quite similar
LICENSE=	mpl-1.0 AND modified-bsd

CONFLICTS+=	pwlib-[0-9]*

USE_TOOLS+=		bison flex gmake pkg-config
BUILD_TARGET=		optshared
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-httpforms
CONFIGURE_ARGS+=	--enable-httpsvc
CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--enable-jabber
CONFIGURE_ARGS+=	--enable-vxml
CONFIGURE_ARGS+=	--enable-xmlrpc
CONFIGURE_ARGS+=	--enable-soap
CONFIGURE_ARGS+=	--enable-oss
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

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	video4l2

.if ${OPSYS} != "DragonFly"
CONFIGURE_ARGS+=	--enable-v4l2
PLIST.video4l2=		yes
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/version.h ${DESTDIR}${PREFIX}/share/ptlib

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/libv4l/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
