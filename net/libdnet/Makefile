# $NetBSD: Makefile,v 1.9 2005/04/11 21:46:49 tv Exp $
#

DISTNAME=	libdnet-1.10
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdnet/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://libdnet.sourceforge.net/
COMMENT=	C interface to several low-level networking routines

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "alpha"
CONFIGURE_ARGS+=	--without-check
.endif

.include "../../mk/bsd.pkg.mk"
