# $NetBSD: Makefile,v 1.6 2011/04/22 14:40:40 obache Exp $

DISTNAME=	sysbench-0.4.12
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sysbench/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sysbench.sourceforge.net/
COMMENT=	Modular, cross-platform and multi-threaded benchmark tool

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PTHREAD_AUTO_VARS=	yes
MAKE_FLAGS+=		bin_SCRIPTS= # don't install problematic scripts

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CFLAGS+=		-D_NETBSD_SOURCE # hack for ulong along with patch-aa
.endif

.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
