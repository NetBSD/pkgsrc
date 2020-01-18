# $NetBSD: Makefile,v 1.9 2020/01/18 23:30:51 rillig Exp $

DISTNAME=	djmount-0.71
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djmount/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://djmount.sourceforge.net/
COMMENT=	FUSE filesystem for accessing Media Server content via UPnP

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--with-external-libupnp
CONFIGURE_ARGS+=	--with-libupnp-prefix=${BUILDLINK_PREFIX.libupnp}

INSTALLATION_DIRS=	share/doc/djmount

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/djmount

.include "../../devel/readline/buildlink3.mk"
.include "../../net/libupnp/buildlink3.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
