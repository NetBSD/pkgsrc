# $NetBSD: Makefile,v 1.26 2023/10/24 22:08:17 wiz Exp $

DISTNAME=	httperf-0.9.0.20190829
PKGREVISION=	1
CATEGORIES=	benchmarks www
MASTER_SITES=	${MASTER_SITE_GITHUB:=httperf/}
GITHUB_TAG=	568322e493046df1e61bf8507c6253ef2831215f

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/httperf/httperf
COMMENT=	Popular web server benchmarking program
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf autoreconf automake
CFLAGS+=	-DFD_SETSIZE=16424

LDFLAGS.SunOS+=	-lsocket -lnsl -lresolv

CONFIGURE_ARGS+=	--enable-idleconn
CONFIGURE_ARGS.SunOS+=	--with-epoll=no

INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR} \
			bindir=${PREFIX}/bin

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
