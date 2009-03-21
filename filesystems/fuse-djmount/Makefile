# $NetBSD: Makefile,v 1.2 2009/03/21 05:44:05 agc Exp $

DISTNAME=	djmount-0.71
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djmount/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://djmount.sourceforge.net/
COMMENT=	FUSE filesystem for accessing Media Server content via UPnP

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

PREFER.readline=	pkgsrc

CONFIGURE_ARGS+=	--with-external-libupnp
CONFIGURE_ARGS+=	--with-libupnp-prefix=${PREFIX}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/djmount
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/djmount

.include "../../devel/readline/buildlink3.mk"
.include "../../net/libupnp/buildlink3.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
