# $NetBSD: Makefile,v 1.2 2007/03/06 21:53:56 rmind Exp $

DISTNAME=		sysbench-0.4.8
CATEGORIES=		benchmarks
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sysbench/}

MAINTAINER=		fuyuki@hadaly.org
HOMEPAGE=		http://sysbench.sourceforge.net/
COMMENT=		Modular, cross-platform and multi-threaded benchmark tool

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
