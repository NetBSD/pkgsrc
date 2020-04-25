# $NetBSD: Makefile,v 1.8 2020/04/25 17:42:53 rillig Exp $

DISTNAME=	liblo-0.31
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
