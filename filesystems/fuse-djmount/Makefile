# $NetBSD: Makefile,v 1.4 2009/07/08 16:33:38 joerg Exp $

DISTNAME=	djmount-0.71
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djmount/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://djmount.sourceforge.net/
COMMENT=	FUSE filesystem for accessing Media Server content via UPnP

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

PREFER.readline=	pkgsrc

CONFIGURE_ARGS+=	--with-external-libupnp
CONFIGURE_ARGS+=	--with-libupnp-prefix=${PREFIX}

INSTALLATION_DIRS=	share/doc/djmount

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/djmount

.include "../../devel/readline/buildlink3.mk"
.include "../../net/libupnp/buildlink3.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
