# $NetBSD: Makefile,v 1.9 2020/10/30 12:18:57 nia Exp $

DISTNAME=	liblo-0.31
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=liblo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://liblo.sourceforge.net/
COMMENT=	Lightweight Open Sound Control implementation
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

CFLAGS+=		${PTHREAD_CFLAGS}
PKGCONFIG_OVERRIDE+=	liblo.pc.in
PTHREAD_OPTS+=		require
RESOLV_AUTO_VARS=	yes	# gethostbyname and friends

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
