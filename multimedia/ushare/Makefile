# $NetBSD: Makefile,v 1.7 2013/03/16 06:20:48 obache Exp $
#

DISTNAME=	ushare-1.1a
PKGREVISION=	5
CATEGORIES=	net multimedia
MASTER_SITES=	http://ushare.geexbox.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://ushare.geexbox.org/
COMMENT=	UPnP AV Mediaserver
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_PKGINSTALL=	yes
USE_TOOLS+=	gmake pkg-config

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--with-libupnp-dir=${BUILDLINK_PREFIX.libupnp}
CONFIGURE_ARGS+=	--enable-dlna
CONFIGURE_ARGS+=	--with-libdlna-dir=${BUILDLINK_PREFIX.libdlna}

BROKEN_GETTEXT_DETECTION=	yes

CONF_FILES=	${PREFIX}/share/examples/ushare/ushare.conf ${PKG_SYSCONFDIR}/ushare.conf
RCD_SCRIPTS=	ushare

INSTALL_MAKE_FLAGS+=	sysconfdir=${DESTDIR}${PREFIX}/share/examples/ushare

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/ushare.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/libdlna/buildlink3.mk"
.include "../../net/libupnp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
