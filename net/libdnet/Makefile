# $NetBSD: Makefile,v 1.7 2005/02/06 23:57:03 adrianp Exp $
#

DISTNAME=	libdnet-1.8
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdnet/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://libdnet.sourceforge.net/
COMMENT=	C interface to several low-level networking routines

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "alpha"
CONFIGURE_ARGS+=	--without-check
.endif

.include "../../mk/bsd.pkg.mk"
