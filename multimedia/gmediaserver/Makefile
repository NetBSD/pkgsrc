# $NetBSD: Makefile,v 1.1.1.1 2010/05/20 04:27:33 obache Exp $

DISTNAME=		gmediaserver-0.13.0
CATEGORIES=		multimedia net
MASTER_SITES=		http://download.savannah.gnu.org/releases/gmediaserver/

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gmediaserver/
COMMENT=		UPnP compatible media server for the GNU system
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		perl pkg-config gmake makeinfo msgfmt
GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_PKGLOCALEDIR=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-id3lib=${BUILDLINK_PREFIX.id3lib}
CONFIGURE_ARGS+=	--with-libupnp=${BUILDLINK_PREFIX.libupnp}

RCD_SCRIPTS=		gmediaserver

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OS_VERSION:R} <= 4
LIBS+=			-lz
.endif

.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/libupnp/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
