# $NetBSD: Makefile,v 1.1.1.1 2008/09/22 23:41:42 jmcneill Exp $
#

DISTNAME=		opal-3.4.1
CATEGORIES=		devel net comms
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/opal/3.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ekiga.net/
COMMENT=		Open Phone Abstraction Library

OPALLIBDIR=		${DISTNAME}

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BUILD_TARGET=		opt

CONFIGURE_ARGS+=	--enable-h264
# ekiga developers say that the ffmpeg-h263 plugin is
# not used and should be disabled in favour of the
# h263+ plugin, so do so
CONFIGURE_ARGS+=	--disable-ffmpeg-h263

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_TOOLS+=		pkg-config

PLIST_SUBST+=		OPALLIBDIR=${OPALLIBDIR:Q}

.if "${MACHINE_ARCH}" == "i386"
PLIST_SUBST+=		LIBARCH=x86
.else
PLIST_SUBST+=		LIBARCH=${MACHINE_ARCH:Q}
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/opal
	${INSTALL_DATA} ${WRKSRC}/opal_inc.mak ${DESTDIR}${PREFIX}/share/opal
	${INSTALL_DATA} ${WRKSRC}/version.h ${DESTDIR}${PREFIX}/share/opal

.include "../../devel/ptlib/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
