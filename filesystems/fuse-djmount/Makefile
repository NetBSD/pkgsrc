# $NetBSD: Makefile,v 1.7 2012/10/03 16:08:31 asau Exp $

DISTNAME=	djmount-0.71
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djmount/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://djmount.sourceforge.net/
COMMENT=	FUSE filesystem for accessing Media Server content via UPnP

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

USE_GNU_READLINE=	yes

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
