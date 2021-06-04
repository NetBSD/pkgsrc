# $NetBSD: Makefile,v 1.11 2021/06/04 19:04:10 adam Exp $

DISTNAME=	djmount-0.71
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djmount/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://djmount.sourceforge.net/
COMMENT=	FUSE filesystem for accessing Media Server content via UPnP
LICENSE=	gnu-gpl-v2

BROKEN=		"Does not build with neither external or internal libupnp"

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-external-libupnp
CONFIGURE_ARGS+=	--with-libupnp-prefix=${BUILDLINK_PREFIX.libupnp}

# compatibility with ancient libixml (part of libupnp)
CPPFLAGS+=	-DIN="" -DOUT="" -DINOUT=""

INSTALLATION_DIRS=	share/doc/djmount

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/djmount

.include "../../devel/readline/buildlink3.mk"
.include "../../net/libupnp/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
